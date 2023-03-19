//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
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
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+1,M=std::__lg(N)+1,inf=0x3f3f3f3f;
int n,st[M][N],a[N],ans=inf;
int ask(int l,int r){
	int t=std::__lg(r-l+1);
	return std::__gcd(st[t][l],st[t][r-(1<<t)+1]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],st[0][i]=a[i];
	for(int j=1;(1<<j)<=n;j++)for(int i=1;i+(1<<j)-1<=n;i++)
		st[j][i]=std::__gcd(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	for(int i=1;i<=n;i++){
		int p=i;
		if(a[i]==1)goto calc;
		for(int j=std::__lg(n);~j;j--)
			if(p+(1<<j)<=n&&ask(i,p+(1<<j))>1)p+=(1<<j);
		if(p==n&&ask(i,p)!=1)continue;
		calc:cmin(ans,p-i+n);
	}
	cout<<(ans==inf?-1:ans);
	return 0;
}