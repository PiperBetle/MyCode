# [`vector` 存图](https://www.cnblogs.com/bxjz/p/graph-vector.html)
只要不存反边，点数小于 $10^7$ 就是短！
# 离散化
```cpp
basic_string<int>b;
for(int i=1;i<=n;i++)b+=a[i];
sort(all(b));b.erase(unique(all(b)),b.end());
for(int i=1;i<=n;i++)a[i]=int(lower_bound(all(b))-b.begin())+1;
```
# [Old Drive Tree](https://www.cnblogs.com/bxjz/p/odt-learn.html)
也就是 odt，珂朵莉树，老司机树，颜色段均摊。
# dijkstra & SPFA
感觉非常常见了吧？QwQ  
01dj 和 SPFA 也差不多，相信大家都能写。
```cpp
std::vector<pii>g[N];
int n,m,s,dis[N];
bool vis[N];
std::priority_queue<pii,std::vector<pii>,std::greater<>>q;
dis[s]=0;q.emplace(0,s);
for(;!q.empty();){
	int u=q.top().second;q.pop();
	if(vis[u])continue;else vis[u]=true;
	for(auto[v,t]:g[u])if(dis[v]>dis[u]+t){
		dis[v]=dis[u]+t;
		if(!vis[v])q.emplace(dis[v],v);
	}
}
```
# [ABC158D](https://atcoder.jp/contests/abc158/tasks/abc158_d)
你有一个字符串 $s$，接下来有 $q$ 次操作。
- 翻转 $s$。
- 在 $s$ 的开头插入字符 $c$。
- 在 $s$ 的结尾插入字符 $c$。

所有操作结束后，输出 $s$。  
$|s|\le10^5$，$q\le2\times10^5$

虽然用普通数组都能写但是得写的非常仔细才可以，但是用 `deque` 可以大大降低码量和调试难度！开 $q_1$ 表示正向字符串，$q_2$ 表示逆向字符串。操作 $1$ 就交换 $q_1$ 和 $q_2$（这是 $\mathcal O(1)$ 的）。操作 $2$ 就在 $q_1$ 头部和 $q_2$ 尾部插入 $c$。操作 $2$ 就在 $q_1$ 尾部和 $q_2$ 头部插入 $c$。
# [CF1620E](https://codeforces.com/problemset/problem/1620/E)
有一个栈，$q$ 次操作。
- 在序列末尾插入 $x$。
- 把序列中所有 $x$ 改成 $y$。

$q,x,y\le5\times10^5$

不可以真的去改吧？对于每个 $x$ 开个链表 $l$，插入 $x$ 就在 $l_x$ 尾部放入 $x$，修改就把 $l_x$ 扔到 $l_y$ 里面。复杂度高达 $\mathcal O(q)$，最优。也可以使用 `vector` 或 `basic_string` 启发式合并，$\mathcal O(q\log q)$。
# [LGP1360](https://www.luogu.com.cn/problem/P1360)
有 $n$ 天 $m$ 种技能，每天会给定 $x$，若 $x$ 二进制下第 $y$ 位是 $1$，那么第 $y$ 种技能会提升 $1$。  
如果一段时间内，所有技能都提升了相同的值，那这段时间就是均衡时期。问：最长的均衡时期？  
$n\le10^5$，$m\le30$

以第一个技能为基准。如果第一个技能进行了提升，就把所有元素都减去一次提升。这样记录的就是其他技能相对于第一个技能的值。  
开个 `map<vector<int>,int>` 表示技能出现时的天数，这样每天计算完后去和 `map` 里面更新。
# [QOJ20](https://qoj.ac/problem/20)
给定一个 $n\times m$ 的 $01$ 地图。$0$ 不能走。只能往右或者往下走。给定 $q$ 次询问，问能否从 $(x_1,y_1)$ 走到 $(x_2,y_2)$。  
$n,m\le1000$，$q\le10^6$

分治。把 $[1,n]$ 分成 $[1,\lfloor\frac n2\rfloor]$ 和 $[\lfloor\frac n2\rfloor+1,n]$ 两部分，如果一个询问正好被分成两部分，就把中间那一列取出来，以每个点为起点跑最短路。如果中间某个点能走到 $(x_1,y_1)$ 且能走到 $(x_2,y_2)$ 那这个询问的答案就是 `YES`。每次 $m$ 个点要跑 $n\times m$ 的最短路，递归  $\log n$ 次所以总复杂度是 $\mathcal O(nm^2\log n)$。  
如果横着分治一次，竖着分治一次，横着分治一次，竖着分治一次，横着分治一次，竖着分治一次……的话，复杂度会变成 $\mathcal O(nm^2)$。[证明](https://loj.ac/d/2828)。  
如果直接采用 `bitset` 去表示中间的一列点（或者横着的一行点），一个点能到达的点就是这个点的右边或上这个点下面的点。判断能否相连就是判断这两个点与起来带不带 $1$。复杂度是 $\mathcal O(\frac{nm^2}{\omega})$。
# [UVA12538](https://www.luogu.com.cn/problem/UVA12538)
$n$ 次操作。
- 从 $p$ 位置插入字符串 $s$，记录版本。
- 从 $p$ 位置删除长度为 $c$ 的字符串，记录版本。
- 输出在第 $v$ 个版本中输出从 $p$ 位置开始长度为 $c$ 的字符串。

$n\le5\times10^4$，$\sum|s|\le10^6$，$|\texttt{输出字符串}|\le 20000$，强制在线，每个 $p,s,c,v$ 都要减去之前输出字符串中 `c` 的数量，保证减去后 $p,s,c,v$ 均合法。

采用 `rope` 维护 `insert` `erase` `substr` 即可，复杂度 $\mathcal O(n\sqrt n)$。（也可可持久化 FHQ Treap）
# [ABC273E](https://atcoder.jp/contests/abc273/tasks/abc273_e)
$q$ 次操作。
- 在序列尾部插入 $x$。
- 删除序列尾部。
- 在第 $x$ 页中写入当前序列。
- 把当前序列变成第 $x$ 页的序列。

每次操作后输出最后一个元素，如果序列为空输出 $-1$。  
$1\le q\le5\times10^5$，$x\le10^9$

发现 $x$ 竟然有 $10^9$！采用 `map<int,rope<int>>` 去维护 `push_back` `pop_back` `operator=` 就行了。
# [LGP1110](https://www.luogu.com.cn/problem/P1110)
给定 $n$ 个队列，初始时第 $i$ 个里面有一个元素 $a_i$，记录这 $n$ 个队列首尾相接的结果为 $b$。
- 在第 $i$ 个队列末尾插入元素 $k$。
- 查询 $b$ 中相邻元素差值的最小值。
- 查询 $b$ 中所有元素差值的最小值。

$n,m\le5\times10^5$，$a_i,k\le5\times10^8$

使用 `multiset` 可以速通本题。操作 $2$ 在插入时删除新插入点相邻的差，插入插入值和相邻的差就行了。全局最值在插入时与和这个数最近的两个数更新答案。
# [AGC020C](https://atcoder.jp/contests/agc020/tasks/agc020_c)
给定一个长度为 $n$ 的序列，显然这个序列有 $2^n-1$ 个非空子集。问这些子集的中位数是多少？  
$n,a_i\le2000$

这些非空子集必然是对称的，也就是说如果一个子集比中位数小，把所有取的数不取，不取的数取，所得到的子集必然比中位数大。因为不考虑空序列所以中位数一定是比 $\lfloor\frac{sum}2\rfloor$ 大的最小的子集。怎么找？`bitset` $01$ 背包，`f|=f<<x`。复杂度 $\mathcal O(\frac{n^2m}\omega)$。
# [CF1141F](https://codeforces.com/contest/1141/problem/F2)
有一个长度为 $n$ 的序列，需要从里面选出尽可能多的互不相交子串，使得所有子串的和相等并且使子串的数量最多，输出那些子串。  
$n\le1500$，$-10^5\le a_i\le10^5$

发现 $n\le1500$ 所以直接弄出所有子串，可以把子串按和扔到 `map` 里，每次就只要从里面选尽可能多的不相交的就行了。选出尽可能多的不相交的子串可以采取贪心，按照右端点从小到大排序，能选就选就行了。复杂度是 $\mathcal O(n^2\log n^2)=\mathcal O(n^2\log n)$。
# [LGP3377](https://www.luogu.com.cn/problem/P3377)
有 $n$ 个小根堆，初始时第 $i$ 个里面有一个元素 $a_i$。
- 合并第 $x$ 个数和第 $y$ 个数所在的堆。​
- 输出并删除 $x$ 个数所在的堆堆的队顶（若有多个最小数，优先删除先输入的），若已被删除，输出 $-1$。

$n,m\le10^5$，$a_i\le2^{31}-1$

同时维护可并堆和并查集，同时维护数有没有被删掉即可。使用 `pbds` 可以做到 $\mathcal O(n\log n)$。对于编号关系可以在堆中插入 `pair`，在 `second` 存放编号。
# [LGP1456](https://www.luogu.com.cn/problem/P1456)
有 $n$ 只猴猴，第 $i$ 只的武力值为 $a_i$，开始时互相不认识。现在发生了 $m$ 场冲突，冲突时猴猴 $x$ 和猴猴 $y$ 会叫上自己所有的朋友（如果 $x$ 和 $y$ 认识冲突就不会发生），从里面选出武力值最高的进行打架。打架后的猴猴武力值减半（向下取整），然后这两群猴猴都会互相认识。对于每次冲突，如果两只猴猴认识对方，输出 $-1$，否则输出打架后他们朋友中武力值最高的猴猴的武力值。  
$n,m\le10^5$，$a_i\le32768$

同时维护可并堆和并查集。
# [LGP6136](https://www.luogu.com.cn/problem/P6136)
有一颗平衡树，起初有 $n$ 个元素为 $a_i$，有 $m$ 种操作。
- 插入一个 $x$。
- 删除一个 $x$。
- 查询 $x$ 的排名。
- 查询排名为 $x$ 的数（如果不存在，则认为是排名小于 $x$ 的最大数）。
- 求 $x$ 的前驱。
- 求 $x$ 的后继。

强制在线，$x$ 异或上次输出的值。保证每次操作合法。  
$n\le10^5，m\le10^6$，$a_i,x<2^{30}$

平衡数板子，`pbds` 维护 `insert` `erase` `order_of_key` `find_by_order` `lower_bound` 即可。由于默认的 `pbds` 是不可重的，需要元素使用 `pair` 储存带一个时间戳。
# [LGP1486](https://www.luogu.com.cn/problem/P1486)
有 $q$ 条指令，工资下界为 $m$，如果有人工资低于下界就离职。
- 在公司中加入工资为 $k$ 的员工，如果 $k<m$ 则直接离开公司。
- 把每位员工工资加上 $k$。
- 把每位员工工资减去 $k$。
- 查询工资第 $k$ 多的员工，如果 $k$ 大于目前员工数目输出 $-1$。

$n\le3\times10^5$，$m\le10^9$

全局加全局减？打个 tag 就行了。注意全局减后有些人会离职，使用 `split` 操作就可以快速解决。只需要用到 `insert` `split` `find_by_order` 就可以在 $\mathcal O(q\log q)$ 解决。
# [CF1732D2](https://codeforces.com/problemset/problem/1732/D2)
起初有一个集合，有一个元素 $0$，$q$ 次操作。
- 在集合中插入元素 $x$（保证之前集合里没有 $x$）。
- 在集合中删除元素 $x$（保证之前集合里有 $x$）。
- 求最小非负整数且为 $x$ 的倍数，这个数不能在集合里。

$q\le2\times10^5$，$x\le10^{18}$

大手一挥开三个集合。$s$ 表示题面的那个集合，$ds_k$ 有可能成为 $k$ 的倍数的答案的集合，$fc_k$ 表示 $k$ 的因子的集合。操作 $1$ 直接在 $s$ 中插入 $x$。操作 $2$ 在 $s$ 中删除 $x$，并且给所有 $ds_i,i\in fc_x$ 插入 $x$，使这个数在下次被操作 $3$ 便利时考虑到。操作 $3$ 在 $ds_x$ 中从小到大遍历过去每次取 $ds_x$ 的首个元素（如果为空，就把上次的值加 $x$）。这样如果不考虑 `set` 的复杂度，复杂度就是调和级数 $\mathcal O(q\log q)$。