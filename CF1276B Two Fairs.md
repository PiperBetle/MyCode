给定图和两个点 $p_1,p_2$，问有多少点对满足这对点之间的路径必须经过 $p_1,p_2$。

预处理出 $p_1,p_2$ 能够以不通过对方到达的点。  
如果这个点同时可以到达两个点，这个点必然可以只通过 $p_1,p_2$ 到达图里的所有点。  
如果一个点不能到达点这两个点，这个点肯定没有任何贡献。（真的有这种点吗?）  
如果一个点只能到达 $p_1$ 不能到达 $p_2$，另一个点只能到达 $p_2$ 不能到达 $p_1$，把这两个点连起来，就是一对合法点了。那就把这两种点的数量乘起来就行了。记得开 `long long`。
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
using bsi=std::basic_string<int>;
constexpr int N=2e5+1;
bsi g[N];
bool v1[N],v2[N];
int n,m,p1,p2,c1,c2;
void dfs1(int u){v1[u]=true;for(int v:g[u])if(!v1[v]&&v!=p2)dfs1(v);}
void dfs2(int u){v2[u]=true;for(int v:g[u])if(!v2[v]&&v!=p1)dfs2(v);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m>>p1>>p2;c1=c2=0;
		memset(v1+1,0,sizeof(bool)*n);memset(v2+1,0,sizeof(bool)*n);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
		dfs1(p1);dfs2(p2);
		for(int i=1;i<=n;i++)c1+=(v1[i]&&!v2[i]&&i!=p1),c2+=(!v1[i]&&v2[i]&&i!=p2);
		cout<<1ll*c1*c2<<'\n';
	}
	return 0;
}
```