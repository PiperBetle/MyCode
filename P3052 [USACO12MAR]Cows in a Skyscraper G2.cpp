#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=18;
int n,m,a[N];
pii f[1<<N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	memset(f+1,0x3f,sizeof(pii)*((1<<n)-1));
	for(int k=0;k<(1<<n);k++)for(int i=0;i<n;i++){
		if(k&(1<<i))continue;
		int j=k|(1<<i);pii t=f[k];
		if(t.se+a[i]>m)cmin(t.se,a[i]),t.fi++;
		else if((t.se+=a[i])==m)t.fi++,t.se=0;
		cmin(f[j],t);
	}
	cout<<(f[(1<<n)-1].fi+=!!f[(1<<n)-1].se);
	return 0;
}