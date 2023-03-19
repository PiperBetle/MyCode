#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=4e5+1,MOD=1e9+7;
constexpr int add0(int x,int y){return (x+=y)<MOD?x:x-MOD;}
constexpr int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
constexpr int sub0(int x,int y){return (x-=y)<0?x+MOD:x;}
constexpr int&sub1(int&x,int y){return (x-=y)<0?x+=MOD:x;}
constexpr int mul(const std::initializer_list<int>&x){loli y=1;for(int i:x)(y*=i)%=MOD;return int(y%MOD);}
std::basic_string<int>g[kN];
int fac[kN],ifa[kN],n,f[kN],sz[kN];
constexpr int qp(int a,int b,int t=1){for(;b;b>>=1,a=mul({a,a}))if(b&1)t=mul({a,t});return t;}
constexpr int inv(int a){return qp(a,MOD-2);}
int binum(int x,int y){return mul({fac[x],ifa[y],ifa[x-y]});}
void dfs1(int u,int fa){
	int cnt=0;sz[u]=f[u]=1; 
	for(int v:g[u])if(v!=fa){
		dfs1(v,u);
		sz[u]+=sz[v];
		f[u]=mul({f[u],f[v],binum(cnt+sz[v],sz[v])});
		cnt+=sz[v];
	}
}
void dfs2(int u,int fa){
	for(int v:g[u])if(v!=fa)
		f[v]=mul({f[u],inv(binum(n-1,sz[v])),binum(n-1,n-sz[v])}),dfs2(v,u);
}
signed main(){
//	freopen("e.in","r",stdin);
//	freopen("e.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;fac[0]=fac[1]=ifa[0]=ifa[1]=1;
	for(int i=2;i<kN;i++)fac[i]=mul({fac[i-1],i});
	ifa[kN-1]=qp(fac[kN-1],MOD-2);
	for(int i=kN-2;i>=2;i--)ifa[i]=mul({ifa[i+1],i+1});
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dfs1(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++)cout<<f[i]<<'\n';
	return 0;
}