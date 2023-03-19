#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
int n,m;
pii a[kN];
std::basic_string<int>g[kN];
std::map<pii,int>mp;
void dfs(int u,int fa,int c){for(int v:g[u])if(v!=fa)mp[{u,v}]=mp[{v,u}]=c,dfs(v,u,(++c)%=m);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u,a[i]={u,v};
	int rt=int(std::max_element(g+1,g+1+n,[](cauto &x,cauto &y){return siz(x)<siz(y);})-g);
	m=siz(g[rt]);dfs(rt,0,0);cout<<m<<'\n';
	for(int i=1;i<n;i++)cout<<mp[a[i]]+1<<'\n';
	return 0;
}