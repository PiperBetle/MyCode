存边，是 $99\%$ 的图论题都会用到的，OIer 的主流是采取链式前向星的写法，记录 `head` 数组表示第 $i$ 个点的第一条边，`next` 数组表示下一条边的编号，`go` 数组表示这条边走向哪里，还可以记录个 `val` 表示这条边的权值。链式前向星的优点是寻找反边，删除边比较方便，缺点是比较难（？，至少我学了 $3$ 个月）理解，内存访问不连续在大数据下慢。
代码：
```cpp
int l,hed[N],nxt[N],go[N],val[N];
void add(int u,int v,int w){
	nxt[++l]=hed[u];
	go[l]=v;
	val[l]=w;
	hed[u]=l;
}
void solve(int u){
	for(int j=hed[u];j;j=nxt[j]){
		int v=go[j],w=val[j];
		// solve
	}
}
```
这个时候就要讲拯救了我 $3$ 个月的 `vector` 法。  
这里的 `vector` 并不只是 `vector`，同样包括 `basic_string`，`(unordered_)map/set` 等 STL。这里也给出示范。
```cpp
using pii=std::pair<int,int>;
std::vector<pii>g[N];
void add(int u,int v,int w){
	g[u].emplace_back(v,w);
}
void solve(int u){
	for(auto[v,w]:g[u]){
		// solve
	}
}
```
对于去除重边，`vector` 异常方便，只需要对 `vector` 进行去重就行了！简单的删边就可以使用 `(unordered_)map/set` 去直接删除。不过会增加一个小小的常数复杂度。  
```cpp
#define all(x) std::begin(x),std::end(x)
sort(all(g[i]));
g[i].erase(unique(all(g[i])),g[i].end());
```
这个有人肯定又要说了，我想写网络流，要记反边，删前缀边，`vector` 就做不到了？吗？其实是可以的。  
`vector` 能通过异或 $1$ 来获取反边的编号，只要在 `vector` 那边也采用编号的储存开个内存池，`vector` 里面记录编号就行了。
```cpp
#define siz(x) int((x).size())
using bsi=std::basic_string<int>;
std::vector<pii>e
bsi g[N];
void add(int u,int v,int w){
	g[u]+=siz(e);e.emplace_back(v,w);
	g[v]+=siz(e);e.emplace_back(u,w);
}
void del(int u){
	for(int j:e){
		auto[v,w]=e[j];
		del[j]=del[j^1]=true;
	}
}
```
至于删边也是差不多的。
```cpp
bsi::iterator hed[N];
void init(){
	for(int i=1;i<=n;i++)
		hed[i]=g[i].begin();
}
void del(int u){
	for(auto it=hed[u];it!=g[u].end();++it){
		hed[u]=next(it);// 这个 next 是 STL 里的函数
	}
}
```
再次介绍一下 `basic_string`，`basic_string` 相当于弱化版的 `vector` 里面只能存不带有构造函数的类型（这也是 `basic_string` 没有 `emplace_back` ），`basic_string` 的访问插入删除都比 `vector` 更快，但是空间消耗 `basic_string` 是 $32$ 字节而 `vector` 只要 `24` 字节。其他区别就是 `basic_string` 的函数更多比如 `substr` 之类的，更别说 `operator+=` 以及 `basic_string_view` 了。