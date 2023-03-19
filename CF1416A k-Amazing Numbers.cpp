#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=3e5+1,inf=0x3f3f3f3f;
int n,a[N],b[N],l[N],p[N];
template<typename any>inline any cmin(any &x,const any &y){if(y<x)x=y;return x;}
template<typename any>inline any cmax(any &x,const any &y){if(x<y)x=y;return x;}
template<typename any,typename...args>inline any cmax(any &x,const any &y,const args &...z){cmax(x,y);return cmax(x,z...);}
template<typename any,typename...args>inline any cmin(any &x,const any &y,const args &...z){cmin(x,y);return cmin(x,z...);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;for(p[0]=inf;T--;){
		cin>>n;
		memset(l+1,0,sizeof(int)*n);
		memset(b+1,0,sizeof(int)*n);
		memset(p+1,0x3f,sizeof(int)*n);
		for(int i=1;i<=n;i++)cin>>a[i],cmax(b[a[i]],i-l[a[i]]),l[a[i]]=i;
		for(int i=1;i<=n;i++)cmax(b[a[i]],n+1-l[a[i]]);
		for(int i=1;i<=n;i++)cmin(p[b[a[i]]],a[i]);
		for(int i=1;i<=n;i++)cout<<(cmin(p[i],p[i-1])==inf?-1:p[i])<<' ';
		cout<<'\n';
	}
	return 0;
}