很有意思的 dp 题。

因为每个节点可以染 $k$ 个颜色每个颜色只能染两个。所以要按照边来染色。再发现其实可以抛开颜色，从权值的角度去看。  
形式化题意：对于每个节点可以选择相邻的 $k$ 个节点选择紧密连接。紧密连接的点可以获得边权。给定一种方案使得权值和最大。

看着很想树形 dp。就去想怎么 dp。想要树形 dp 就得和子树无关。使用 $f_{i,0}$ 表示节点 $i$ 染了 $k-1$ 个颜色（留一个颜色给 $fa_i$ 去紧密连接），使用 $f_{i,1}$ 表示节点 $i$ 染了 $k$ 个颜色（不留颜色给 $fa_i$ 去紧密连接）。  
对于节点 $u$ 的每个下一层的节点 $v$，直接具有 $f_{v,1}$，带不带这条边的差值是 $w+f_{v,0}-f_{v,1}$，那把所有 $f_{v,1}$ 累加起来，然后从所有 $w+f_{v,0}-f_{v,1}$ 中选择前 $k-1$ 个正数加给 $f_{u,0}$，选择前 $k$ 个正数加给 $f_{u,0}$。

```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define siz(x) int((x).size())
#define all(x) std::begin(x),std::end(x)
using std::cin;using std::cout;
using loli=long long;
using pii=std::pair<int,int>;
using bsl=std::basic_string<loli>;
constexpr int N=5e5+1;
int n,m;
std::vector<pii>g[N];
loli f[N][2];
void dfs(int u,int fa){
	bsl b;
	f[u][0]=f[u][1]=0;
	for(auto[v,w]:g[u])if(v!=fa){
		dfs(v,u);
		f[u][0]+=f[v][1];
		f[u][1]+=f[v][1];
		b+=w+f[v][0]-f[v][1];
	}
	sort(all(b),std::greater<>());
	for(int i=0;i<siz(b)&&i<m;i++){	
		if(b[i]<=0)break;
		if(i<m-1)f[u][0]+=b[i];
		f[u][1]+=b[i];
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v,w;i<n;i++)cin>>u>>v>>w,g[u].emplace_back(v,w),g[v].emplace_back(u,w);
		dfs(1,0);
		cout<<f[1][1]<<'\n';
	}
	return 0;
}
```