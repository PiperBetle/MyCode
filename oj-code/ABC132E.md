看了一下题解，发现全是把一个点拆成三个点然后跑分层图最短路的，但是我一看感觉就是普通的 bfs。

题意是在图内询问从 $s$ 到 $t$ 是否存在长度为 $3$ 的路径。不妨开一个数组，$vis_{i,j}$ 表示是否存在从点 $s$ 出发，是否存在长度模 $3$ 是 $j$ 的路线。那么每次更新就是 $vis_{v,(x+1)\bmod3}=vis_{u,x}$，这样复杂度是 $\mathcal O(n+m)$ 的。

很短而且很快的 code：
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr int kN=1e5+1;
std::basic_string<int>g[kN];
using pii=std::pair<int,int>;
bool vis[kN][3];
int n,m,s,t;
signed main(){
//	freopen("checkers.in","r",stdin);
//	freopen("checkers.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v;
	cin>>s>>t;vis[s][0]=true;
	std::queue<pii>q({{s,0}});
	while(!q.empty()){
		auto[u,x]=q.front();x++;q.pop();
		for(int v:g[u])if(!vis[v][x%3]){
			if(v==t&&x%3==0)return cout<<x/3,0;
			vis[v][x%3]=true;
			q.emplace(v,x);
		}
	}
	cout<<"-1";
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}
```
哎呀用 `basic_string` 存图，多是一件美事啊！哎呀，啧啧啧啧，不快不慢（指比 `vector` 快但是略慢于链式前向星），效果真是好极了。这位巨佬，看看，没事吧，用吧，赶快用吧。巨佬，你得带个头，你要不带头用。他，他们怎么能，能敢用呢？诶，都，都 都看我干什么呀？用呀 用呀 用，快，快，赶快用，嘿，赶快用呀！（突然变脸）哎！！！TNND，为什么不用？用！用！不 不用…不用是吧，不用，不用我就啊了你！都不敢用，都怕超时是吧。我告诉你，不用？不用也别想减小码量（ `basic_string` 语法糖，插入可以使用 `+=` 运算符）！既然大家都知道了，这戏我也就不演了……（后省略好多字）