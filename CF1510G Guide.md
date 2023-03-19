题意：给你一棵有 $n$ 个节点的树，你需要累计到达 $k$ 个节点，可以走回头路，不需要回到根节点。输出任意一条最短路径。  
数据范围：$1\le T\le 100$ 组数据，每组数据 $1\le k\le n\le100$，保证 $fa_i\le i$  
尽管 $n\le100$，但是做法是 $\mathcal O(n)$ 的。因为从根节点出发而且不需要回到根节点，容易想到树上最长链。因为 $k$ 个节点的限制，所以这个最长链的深度不能超过 $k$。
因为只有那条链的路不得不走，所以剩下的路其实是可以随便走的。比较恶心的是输出路径，这题有个保证 $fa_i\le i$，可以减少输出难度。对每个点开个 `vis` 数组，为 $1$ 表示这个点在最终路径中。开始时把最长链上的所有 `vis` 设定为 $1$，从根节点开始 `dfs`，在跑的时候每新访问一个点就把剩余计数减一，如果剩余计数为 $0$ 就没有必要访问其他点了。最长链上的点因为 $fa_i\le i$ 这个性质才能保证按照正确的顺序输出。  
如果感觉不太懂可以看看代码的 `dfs2` 部分，code:
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=101;
int n,m,k,cnt,fa[kN],dep[kN];
bool vis[kN];
std::basic_string<int>g[kN];
void dfs1(int u){
	for(int v:g[u])if(v!=fa[u])
		dep[v]=dep[u]+1,dfs1(v);
}
void dfs2(int u){
	cout<<u<<' ';
	for(int v:g[u])if(v!=fa[u]&&cnt&&!vis[v])
		cnt--,dfs2(v),cout<<u<<' ';
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>k;m=1;
		memset(vis+1,0,sizeof(bool)*n);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=2;i<=n;i++)cin>>fa[i],g[fa[i]]+=i;
		dep[1]=1;dfs1(1);
		for(int i=2;i<=n;i++)if(dep[i]<=k&&dep[i]>dep[m])m=i;
		cnt=k-dep[m];
		cout<<(k-1)*2-dep[m]+1<<'\n';
		while(m)vis[m]=true,m=fa[m];
		for(int i=1;i<=n;i++)if(vis[i])dfs2(i);
		cout<<'\n';
	}
	return 0;
}
```