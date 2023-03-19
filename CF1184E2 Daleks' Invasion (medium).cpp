#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<numeric>
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
constexpr int kN=1e5+1,kM=1e6+1,kL=std::__lg(kN)+1,inf=0x3f3f3f3f;
struct edge1{int u,v,t,id;bool fl=true;}s1[kM];
int n,m,l,q,f[kN],dep[kN],p[kN][kL],w[kN][kL];
bool vis[kN];
std::vector<pii>s2[kN];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u){
	vis[u]=true;
	for(auto[v,t]:s2[u])if(!vis[v])dep[v]=dep[u]+1,p[v][0]=u,w[v][0]=t,dfs(v);
}
int LCA(int a,int b,int ans=-1){
	if(dep[a]>dep[b])std::swap(a,b);
	for(int i=l;i>=0;i--)if(dep[a]+(1<<i)<=dep[b])ans=std::max(ans,w[b][i]),b=p[b][i];
	if(a==b)return ans;
	for(int i=l;i>=0;i--)if(p[a][i]!=p[b][i])ans=std::max({ans,w[a][i],w[b][i]}),a=p[a][i],b=p[b][i];
	return std::max({ans,w[a][0],w[b][0]});
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;l=std::__lg(n);
	for(int i=1;i<=m;i++)cin>>s1[i].u>>s1[i].v>>s1[i].t,s1[i].id=i;
	std::iota(f+1,f+1+n,1);
	std::sort(s1+1,s1+1+m,[](cauto&x,cauto&y){return x.t<y.t;});
	for(int i=1,fx,fy;i<=m;i++){
		fx=find(s1[i].u),fy=find(s1[i].v);
		if(fx==fy)continue;else f[fx]=fy,s1[i].fl=false;
		s2[fx].emplace_back(fy,s1[i].t);
		s2[fy].emplace_back(fx,s1[i].t);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i),p[i][0]=i,w[i][0]=-inf;
	for(int j=1;j<=l;j++)for(int i=1;i<=n;i++)
		p[i][j]=p[p[i][j-1]][j-1],w[i][j]=std::max(w[i][j-1],w[p[i][j-1]][j-1]);
	std::sort(s1+1,s1+1+m,[](cauto&x,cauto&y){return x.id<y.id;});
	for(int i=1;i<=m;i++)if(s1[i].fl)cout<<LCA(s1[i].u,s1[i].v)<<'\n';
	return 0;
}