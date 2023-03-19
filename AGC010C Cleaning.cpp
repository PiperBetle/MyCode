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
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e5+1;
std::basic_string<int>g[N];
int n,L[N],R[N],a[N],rt;
inline void dfs(int u,int fa){
	int sl=0,sr=0,mx=0;
	for(int v:g[u])if(v!=fa){
		dfs(v,u);
		cmax(mx,L[v]);
		sl+=L[v];sr+=R[v];
	}
	int k=(mx>=sl/2?sl-mx:sl/2);
	L[u]=2*a[u]-sr;R[u]=2*a[u]-sl;
	if(!sl&&!sr)L[u]=R[u]=a[u];
	cmax(L[u],a[u]-k);
	cmax(L[u],0);
	cmin(R[u],a[u]);
	if(L[u]>R[u])cout<<"NO\n",exit(0);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	if(n==2)return cout<<(a[1]==a[2]?"YES":"NO"),0;
	for(int i=1;i<=n;i++)if(siz(g[i])){rt=i;break;}
	dfs(rt,0);
	cout<<(L[rt]?"NO":"YES");
	return 0;
}