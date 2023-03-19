# [Trick 合集 ![密码保护](https://www.cnblogs.com/images/lock.svg)](https://www.cnblogs.com/Kobe303/p/16353602.html)

记录了一些需要自己记住的东西

> Q：把一个序列 A 变成非严格单调递增的，至少要修改多少个数

> A：总长度减去 A 的最长不下降子序列长度。

------

> Q：把一个序列 A 变成严格单调递增的，至少要修改多少个数

> A：构造序列 B，$Bi=A_{i}−i$，总长度减去 B 的最长不下降子序列长度。

------

> 由 $CF1486E$ 得到一个套路，看到 $w≤50$，发现非常小，就考虑拆点，分层图上跑最短路即可。

------

> 遇到有关 $gcd$ 的式子，如 $gcd(a1,a2,⋯,an)$ 等于某个数，可以考虑枚举 $d$，然后将限制转换成 $gcd$ 是 d 的倍数，将此时求出的记为 $f_{i}$，表示 $gcd$ 是 i 的倍数的时候的答案，然后通过容斥求出 $f′_{i}=f_{i}−∑_{i|j,i<j}\limits{f′_{j}}$。$f′_{i}$ 表示 $gcd$ 恰好等于 i 时的答案。

------

> 看到组合数，可以考虑放到平面直角坐标系上，数形结合巧转化！如 $C(x+y,x)$ 的几何意义就是从 $(0,0)$ 走到 $(x,y)$，只能向上或向右走的路径条数。

------

> KMP 中的 nxt 数组有一个很优秀的性质，当 $i−nxt_{i}$ 能整除 i 时，$S_{1}∼i−nxt_{i}$ 就是 $S_{1}∼i$ 的最小循环元。进一步的，若 $\large{i−nxt_{nxt_{i}}}$ 能整除 i 时，S1∼i−nxtnxtiS1∼i−nxtnxti 就是 S1∼iS1∼i 的次小循环元。依次类推，我们可以找出 S1∼iS1∼i 的所有循环元。

------

> 特殊点有很多时要求每个点到特殊点的最短距离可以考虑建一个超级源点然后向每个特殊点连一条长度为 00 的边，然后就可以跑最短路了。

------

> 一个排列 aa 最少需要交换多少次变成目标排列 pp，对每个 aiai 向 pipi 练一条无向边，最后最小交换次数就是 nn 减去连通块个数。

------

> 有一个经典套路，求两点之间必须经过某一条边的最短路，设这两个点是 x,yx,y，且必须经过 u,vu,v 这条边，那么答案是 min(disx,u+disv,y,disx,v+disu,y)+w(u,v)min(disx,u+disv,y,disx,v+disu,y)+w(u,v)。

------

> 概率题要求保留几位小数，且操作次数非常大时，直接将操作次数与某个较小的数取 minmin，保证误差不超过题目要求且时间复杂度允许。

------

> 图上的构造题可以考虑特殊情况：如图是一棵树时该怎么做。

------

> 定义 parity(x)parity⁡(x) 表示 popcount(x)mod2popcount⁡(x)mod2，则有一个性质为 parity(x⊕y)=parity(x)⊕parity(y)parity⁡(x⊕y)=parity⁡(x)⊕parity⁡(y)。

------

> 从小的数据范围切入！如 CF1399E2，发现代价花费只有两种： 1,21,2。
> 那么对于相同代价的边预处理一遍，然后双指针维护答案即可。

------

> 网络流有一个重要的技巧，**点边转化**，图的节点可以拆为“入点”和“出点”两个，把点的属性体现在“入点”与“出点”之间的边上。图的边也可以分为两截，在中间加一个节点，把边的属性体现在中间的点上。还有在最小割中，容量为 +∞+∞ 的边具有“防止割断”的含义。

------

> 将一个点 (x,y)(x,y) 的坐标变为 (x+y,x−y)(x+y,x−y) 后，原坐标系中的曼哈顿距离等于新坐标系中的切比雪夫距离。将一个点 (x,y)(x,y) 的坐标变为 (x+y2,x−y2)(x+y2,x−y2) 后，原坐标系中的切比雪夫距离等于新坐标系中的曼哈顿距离。哦不对，这玩意好像没啥用（），将坐标系从 (x,y)(x,y) 倾斜到 (x+y,x−y)(x+y,x−y)，答案不变（因为只是换了个视角看）。

------

> Q：一维问题：在一个无限长的数轴上，可以从 xx 移动到 x+1x+1 或 x−1x−1，从 00 移动 XX，移动 NN 步，有多少种方案？

> A：如果 N<|X|N<|X| 或 NN 与 XX 奇偶性不同，显然无解。否则解一个方程，解得走了 N+|X|2N+|X|2 “+1+1” 步，N−|X|2N−|X|2 “−1−1”步，那么方案数为 (NN+|X|2)(NN+|X|2)。

> Q：二维问题：在一个无限的平面直角坐标系中，可以从 (x,y)(x,y) 移动到 (x+1,y)(x+1,y) 或 (x−1,y)(x−1,y) 或 (x,y+1)(x,y+1) 或 (x,y−1)(x,y−1)，从 (0,0)(0,0) 移动到 (X,Y)(X,Y)，移动 NN 步，有多少种方案？

> A：设 (U,V)=(X+Y,X−Y)(U,V)=(X+Y,X−Y)，那么原问题等价于从 (0,0)(0,0) 移动到 (U,V)(U,V)，移动 NN 步的方案数。那么我们发现原来的移动是从 (x,y)(x,y) 移动到 (x+1,y)(x+1,y) 或 (x−1,y)(x−1,y) 或 (x,y+1)(x,y+1) 或 (x,y−1)(x,y−1)，现在的移动是从 (u,v)(u,v) 移动到 (u−1,v−1)(u−1,v−1) 或 (u−1,v+1)(u−1,v+1) 或 (u+1,v−1)(u+1,v−1) 或 (u+1,v+1)(u+1,v+1)，哎，u,vu,v 互不影响了！那么就转化成一维问题了。

> Q：三维问题：太长了不想写，反正就是多了一维。

> A：枚举总共的 NN 步，有 ii 步是给 xx 轴走的，这是个一维问题，那么有 N−iN−i 步是给 (y,z)(y,z) 这个平面走的，这是个二维问题，解决了。

------

> 有一个性质，若 (nm)mod2=1(nm)mod2=1，当且仅当 n&m=mn&m=m。

------

> 二项式反演：
> 至多：fn=∑i=0n(ni)gi⟺gn=∑i=0n(−1)n−i(ni)fifn=∑i=0n(ni)gi⟺gn=∑i=0n(−1)n−i(ni)fi。
> 至少：fn=∑i=nm(in)g(i)⟺g(n)=∑i=nm(−1)i−n(in)f(i)fn=∑i=nm(in)g(i)⟺g(n)=∑i=nm(−1)i−n(in)f(i)

------

> 二维数点可以用主席树来做，具体的，对每一行开一个 `vector`，将每个点存到它这一行中，然后一行行从上往下做，对于每一行，取出这行的 `vector` 中的点，在可持久化线段树中单点修改，然后查询就是一个差分。

------

> 记录一个技巧，来源于 ABC232G。题意大致是给定一张 NN 个节点的完全图，其中 ii 到 jj 的有向边权是 (Ai+Bj)modM(Ai+Bj)modM，问 11 到 NN 的最短路。NN 是 1e51e5 级别，MM 是 1e91e9 级别。直接连边是 O(N2)O(N2) 的，考虑优化建图。构建 MM 个虚点，分别是 0¯¯¯,1¯¯¯,⋯,M−1¯¯¯¯¯¯¯¯¯¯¯¯¯¯0¯,1¯,⋯,M−1¯。然后对于 ∀k∈[0,M−1)∀k∈[0,M−1)，连边 k¯¯¯→k+1¯¯¯¯¯¯¯¯¯¯¯k¯→k+1¯，边权为 11。特别的，M−1¯¯¯¯¯¯¯¯¯¯¯¯¯¯→0¯¯¯M−1¯→0¯。
> 对于 ∀i∈[1,N]∀i∈[1,N]，连边 i→−Ai+M¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯i→−Ai+M¯，边权为 00。对于 ∀i∈[1,N]∀i∈[1,N]，连边 Bi¯¯¯¯¯¯→iBi¯→i，边权为 00。发现正确性得到了保证，但是时间复杂度依旧寄。考虑继续优化，可以发现，环上有用的虚点个数至多 2N2N 个，所以缩点，就可以了。

------

> 遇到有很多项的公式就尽可能的去化简，考虑能不能使每一项独立。

------

> 一个建模的技巧：N×MN×M 的网格图可以想一想能不能把每行和每列抽象成 N+MN+M 个点。

------

> 若函数 f(n)f(n) 满足 f(1)=1f(1)=1 且 ∀x,y∈N∗,gcd(x,y)=1∀x,y∈N∗,gcd(x,y)=1 都有 f(xy)=f(x)f(y)f(xy)=f(x)f(y)，则 f(n)f(n) 为积性函数。欧拉函数与莫比乌斯函数均是积性函数。
>  莫比乌斯函数的定义：μ(n)=⎧⎩⎨10(−1)ω(n)n=1∃d>1,d2∣notherwiseμ(n)={1n=10∃d>1,d2∣n(−1)ω(n)otherwise，其中 ω(n)ω(n) 表示 nn 的本质不同质因子个数。
>  莫比乌斯函数有一个性质：∑d∣nμ(d)={10n=1n≠1∑d∣nμ(d)={1n=10n≠1
>  莫反结论：[gcd(i,j)=1]=∑d∣gcd(i,j)μ(d)[gcd(i,j)=1]=∑d∣gcd(i,j)μ(d)

------

> 反思一下为什么没有独立切掉 ABC229F，甚至没有看出这是一道 DP 题，现在来复盘一下。
> 首先看到题目，要求删去边权和最小的边使得图变成一张二分图，那么看到二分图就想到染色，那么题目的意思就是让同色节点之间的边权之和最小。不失一般性的，强制 00 节点为白色。
> 由于原图是一个环，这不好处理，考虑断开 NN 和 11 之间的边，那么这样就能设计出一个 DP 状态，fi,j,kfi,j,k 表示将前 ii 个节点染色，第 ii 个点的颜色是 jj 且第一个点的颜色是 kk 时所需最小代价，转移不必细说，重点在状态设计，最后还得记得补充 NN 与 11 之间边的贡献。

------

> 来自 ABC229G 的复盘：
> 首先显然能想到二分，随后想想怎么判定，这里我卡住了，看了题解发现是一个常用的技巧。先把所有 YY 的位置存下来，记为数组 AA，记 Bi=Ai−iBi=Ai−i，那么发现交换就相当于把 BB 中某个值加一或减一，后面就是中位数随便搞搞就好了。

------

> 缕清一下 ABC256G。
> 看到题目，首先可以想到枚举每条边上的白色石子个数，记为 kk。
> 则最终答案为 ∑k=0d+1f(k)∑k=0d+1f(k)，f(x)f(x) 表示每条边的石子个数为 xx 时的答案。
> 那么可以想到一个暴力的 dp 状态，设 fi,j,kfi,j,k 表示前 ii 条边，第 ii 条边首颜色是 jj，尾颜色是 kk 时的方案数，那么有转移（记石子颜色为白色则为 00，否则为 11）：fi,0,0=fi−1,0,1×fi−1,1,0fi,0,0=fi−1,0,1×fi−1,1,0，算了不想写了，懂得都懂，然后发现转移跟 ii 没关系，直接矩乘加速就好了。

------

> min(a,b)=a+b−max(a,b)min(a,b)=a+b−max(a,b)

------

> min−maxmin−max 容斥：
> 我们现在有一个全集 U={a1,a2,⋯,an}U={a1,a2,⋯,an}。
> 我们设 min(S)=minai⊆Saimin(S)=minai⊆Sai，对应的 max(S)=maxai⊆Saimax(S)=maxai⊆Sai。
> 假设我们能很轻松的求出任意集合的 min(S)min(S)，但是我们很难求出任意集合的 max(S)max(S)。就可以通过神奇的 min−maxmin−max 容斥来求。
> max(S)=∑T⊆S(−1)|T|+1min(T)max(S)=∑T⊆S(−1)|T|+1min(T)，对称的，min(S)=∑T⊆S(−1)|T|+1max(T)min(S)=∑T⊆S(−1)|T|+1max(T)
> 。比较重要的是，该定理在期望下也成立，也就是说 E(max(S))=∑T⊆S(−1)|T|+1E(min(T))E(max(S))=∑T⊆S(−1)|T|+1E(min(T))。
> 这是非常有用的，因为期望下的 maxmax 和 minmin 是很难求的。

------

> 遇到不确定的边可以考虑建虚点。

------

> 遇到什么统计和，可以考虑枚举和，然后转成统计方案数。

------

> mex=xmex=x 的充要条件是包含了 0∼x−10∼x−1 且不包含 xx，所以可以容斥用包含 0∼x−10∼x−1 的方案数减去包含 0∼x0∼x 的方案数即可得到 mex=xmex=x 的方案数。

------

> 遇到什么要求走 ii 步可以到达的最远位置什么的，可以考虑使用倍增优化。

------

> 做 kk 遍前缀和，aiai 对 anan 的贡献是 (n−i+k−1k−1)(n−i+k−1k−1)。

------

> CF1149C：求 minl<k<rsuml+sumr−2×sumkminl<k<rsuml+sumr−2×sumk。
> 用线段树维护 55 个东西，mxp=maxl≤i≤rsumimxp=maxl≤i≤rsumi，mnp=minl≤i≤rsumimnp=minl≤i≤rsumi，lmxp=maxl≤i≤r{sumi−2×minl≤j≤isumj}lmxp=maxl≤i≤r{sumi−2×minl≤j≤isumj}，rmxp=maxl≤i≤r{sumi−2×mini≤j≤rsumj}rmxp=maxl≤i≤r{sumi−2×mini≤j≤rsumj}，以及 ansp=max(rmxlc+mxrc,lmxrc+mxlc)ansp=max(rmxlc+mxrc,lmxrc+mxlc)。
> 附代码：

```cpp
void pushup(int p) {
		t[p][0] = max(t[ls(p)][0], t[rs(p)][0]);
		t[p][1] = min(t[ls(p)][1], t[rs(p)][1]);
		t[p][2] = max(max(t[ls(p)][2], t[rs(p)][2]), t[ls(p)][0] - 2 * t[rs(p)][1]);
		t[p][3] = max(max(t[ls(p)][3], t[rs(p)][3]), t[rs(p)][0] - 2 * t[ls(p)][1]);
		t[p][4] = max(max(t[ls(p)][4], t[rs(p)][4]), max(t[ls(p)][0] + t[rs(p)][3], t[ls(p)][2] + t[rs(p)][0]));
	}
```

------

> 指数不是模模数，是模数减一！！！

------

> **周期 - Border** 联系紧密，两者不可分割。
> 单串的周期、Border 问题可以用 KMP 求出**失配树**转化为树上问题。
> 经典结论：所有 Border 成 O(logn)O(log⁡n) 个等差数列。

------

> 直径的性质，树上某点的最远点一定是直径的某个端点。

------

> ∑i=rn(ir)=(n+1r+1)∑i=rn(ir)=(n+1r+1)

------

> 一个经典的关于鸽巢原理的题目，从 1∼2M1∼2M 中选出不同的 M+1M+1 个数，总有两个相互整除的。
> 证明：把每个数写成 2k×x2k×x 的形式，其中 xx 是奇数，然后，xx 的取值只会是 1,3,⋯,2M−11,3,⋯,2M−1 这 MM 个数中的一个。显然分解后 xx 相同的两个数是整除关系。而一共有 MM 个不同的 xx，因此，选择 M+1M+1 个数出来，至少会有两个数呈倍数关系。

------

> 链是一个点的集合，这个集合中任意两个元素 u,vu,v，要么 vv 能走到 uu，要么 uu 能走到 vv。
> 反链是一个点的集合，这个集合中任意两点谁也不能走到谁。
> 最大反链是反链中最大的那个。
> 最小链覆盖：用最少的链，覆盖所有的点至少一次。
> Dilworth 引理：最大反链 == 最小链覆盖，而最小链覆盖可以通过拆点求二分图最大匹配得到。（具体咋求就是把原图的点 uu 拆成 u,u+nu,u+n 两个点。然后对于原图的边 u→vu→v 在新图中连边 u→v+nu→v+n，将原图的点作为左部点，其余作为右部点，求二分图最大匹配就可以了）。
> 事实上这个玩意是二分图的一个性质：二分图最大匹配 == n−n− 最大点独立集。
> 二分图最大匹配 == 最小点覆盖 == n−n− 最大点独立集 == n−n− 最小边覆盖。

------

> 经典结论：字符串 SS 的本质不同回文子串个数为 O(|S|)O(|S|)。

------

> 一类求 sumsum 的问题:设 fifi 表示最终的数恰好为 ii 的方案数，则答案为 ∑ifi×i∑ifi×i。如果恰好为 ii 不好求，那么可以转化成设 gigi 表示最终的数大于等于 ii 的方案数，则答案为 ∑igi∑igi。

------

> 冒泡排序一轮对逆序对的变化。
> 结论：假设原本在位置 ii 上的逆序对数为 cici，冒泡排序一轮后，位置 ii 上的逆序对数变为 max(0,ci+1−1)max(0,ci+1−1)。
> 相当于一个左移，减一，与 00 取 maxmax 的过程。

------

> 无向图的两点之间的必经边一定是割边，所以可以用 Tarjan 将边双联通分量缩点缩成一棵树，然后树上的边就是必经边了。

------

> 记一下一个状态的设计：来自 CF1144G。
> 给定一个长度为 nn 的序列 AA，问能否把它拆成一个严格递增序列和一个严格递减序列，如果有解则输出方案。
> 设 fi,0fi,0 表示把序列的前 ii 个数拆成一个递增序列和一个递减序列（可以为空），并且 AiAi 属于递增序列时，递减序列结尾可能的最大值。fi,1fi,1 表示 AiAi 属于递减序列时，递增序列结尾可能的最小值。
> 转移不必细说。

------

> 遇到排列的数数问题，状态不是 fi,jfi,j 表示第 ii 个数填 jj 的方案数（这样转移将不满足排列的性质，每个元素仅出现一次），而是 fi,jfi,j 表示第 ii 个数填的数是前 ii 个数中第 jj 小的。

------

> 几个常见的组合式子：
> kCkn=nCk−1n−1kCnk=nCn−1k−1
> CknCmk=CmnCk−mn−m=Ck−mnCmn−k+mCnkCkm=CnmCn−mk−m=Cnk−mCn−k+mm
> ∑ni=mCmi=Cm+1n+1∑i=mnCim=Cn+1m+1
> ∑n+mi=nCki=Ck+1n+m+1−Ck+1n∑i=nn+mCik=Cn+m+1k+1−Cnk+1
> ∑ki=0CinCk−im=Ckn+m∑i=0kCniCmk−i=Cn+mk
> (a+b)n=∑nk=0(nk)akbn−k(a+b)n=∑k=0n(nk)akbn−k，这个的特殊形式就是容斥的那个式子，取 a=−1,b=1a=−1,b=1 代入得 (1−1)n=∑nk=0(nk)(−1)k=0(1−1)n=∑k=0n(nk)(−1)k=0

------

> 全局打 tag。

------

> 偏序关系定义：自反，反对称，传递。常见的偏序关系，小于等于，大于等于，整除关系，包含关系。

------

> 看到棋盘一定要想到黑白染色。

------

> 遇到某些问题（如 AGC032D），给你一个序列，有什么操作把一个数移来移去什么的，代价是什么，一定要发现某些性质如每个数至多被移动一次以及关注不被移动的数应该满足什么关系。

------

> 来自 CF1592F1：有一个只有 00 和 11 的矩阵，区间翻转矩形不好做，考虑转化成单点修改，所以设 ai,j=(ci,j+ci+1,j+ci,j+1+ci+1,j+1)%2ai,j=(ci,j+ci+1,j+ci,j+1+ci+1,j+1)%2，这样就转化为单点修了。

------

> 来自 CF1223F：奇怪的套路增加了，区间 [l,r][l,r] 能匹配完可以转化为区间 [1,l−1][1,l−1] 匹配完后的状态和区间 [1,r][1,r] 匹配完后的状态一样。因此 Hash 判断即可。

------

> 最大权闭合子图，说白了，要选一个东西，必须把其依赖的东西全部先选上。常见应用是有一类物品，有代价选择，但把指定的一组物品全选了会产生收益。
> 网络流建图方式：源点往有代价物品连其代价，有代价物品往选了它可能产生收益的组连 ∞∞，每个组往汇点连其收益。
> 结论：最大权闭合子图为所有正权点之和减去最小割。

------

> 一个显然的结论是，一棵树最大匹配唯一当且仅当它是单点，或它每个点都包含在最大匹配中（即，最大匹配就是完美匹配）。

------

> 来自 CF1689E，CF1685C，CF1658F：看到样例大胆猜想最多的操作次数不超过两次，然后去想有无两次一定能完成的操作，然后 00 次特判，寻找能否 11 次完成。

------

> 扫描线：遇到一条数轴，给你一些线段，可以看成扫描线，把线段 [l,r][l,r] 拆成两个事件 (l,1),(r+1,−1)(l,1),(r+1,−1)，11 表示加入，−1−1 表示删除。

------

> 子集反演：f(S)=∑T⊆Sg(T)⇔g(S)=∑T⊆S(−1)|S|−|T|f(T)f(S)=∑T⊆Sg(T)⇔g(S)=∑T⊆S(−1)|S|−|T|f(T)
> 特殊的，当运算是异或时，不用考虑 −1−1 的系数。

------

> 裴蜀定理：设 a,ba,b 是不全为零的整数，则存在整数 x,yx,y，使得 ax+by=gcd(a,b)ax+by=gcd(a,b)。事实上只要方程右边是 gcd(a,b)gcd(a,b) 倍数即可。

------

> 给定一张无向图，若存在一条从节点 SS 到节点 TT 的路径，恰好不重不漏地经过每条边一次（可以重复经过图中的节点），则称该路径为 SS 到 TT 的**欧拉路**。
> 特别地，若存在一条从节点 SS 出发的路径，恰好不重不漏地经过每条边一次（可以重复经过图中的节点），最终回到起点 SS，则称该路径为**欧拉回路**。存在欧拉回路的无向图被称为欧拉图。
> **欧拉图的判定**
> 一张无向图为欧拉图，当且仅当无向图连通，并且每个点的度数都是偶数。
> **欧拉路的存在性判定**
> 一张无向图中存在欧拉路，当且仅当无向图连通，并且图中恰好有两个节点的度数为奇数，其他节点的度数都是偶数。这两个度数为奇数的点就是欧拉路的起点 SS 和终点 TT。
