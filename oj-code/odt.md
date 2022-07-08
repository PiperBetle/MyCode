前景提要：以下所有珂朵莉的题**不一定**保证珂朵莉的复杂度正确。

# 基础介绍
珂朵莉（全称珂朵莉树，又名老司机树 Old Drive Tree 简称 odt，中文是老司机树，还可以叫颜色段均摊，下简称珂朵莉）是一种来自 [CF896C Willem, Chtholly and Seniorious](https://www.luogu.com.cn/problem/CF896C) 的暴力数据结构，原理是同时维护所有值相同的元素来达到极低的复杂度维护序列。其保证复杂度的操作是区间推平（等等，你刚刚说了推平？那就能珂朵莉），没有足够多而且足够大的区间推平的话珂朵莉的复杂度就是错的。
珂朵莉维护相同区间的方法是使用 `std::set` 记录每个区间左右端点和权值，当取点时直接在 `std::set` 里 `lower_bound` 即可。
```cpp
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
};
```
这就是珂朵莉最基础的板子，`split` 的作用是把一个区间 $[l,r]$ 分成 $[l,p]$ 和 $[p+1,r]$，代码还是很容易理解的，`assign` 的作用是把 $[l,r]$ 的区间推平，直接 `erase` $l$ 和 $r$ 的迭代器就行了。这里注意 split 的顺序一定要先 `split` $r+1$ （为什么是 $r+1$ ？因为 STL 是左闭右开的所所以要多取一位，这也是为什么珂朵莉刚开始插入初始区间要 `insert` $n+1$ 的原因）再 `split` $l$ 否则会 RE。因为如果 `split` $l$，那么 $l$ 的迭代器可能会在 `split` $r+1$ 的时候被再次分裂导致 $l$ 的迭代器失效。但是如果先 `split` $r+1$，可以保证 $l$ 的迭代器肯定在 $r+1$ 的左边不会对 $r+1$ 生效。这里我直接可以 `erase` 的原因是因为 c++ 对于函数的表达式求值顺序是从右往左的所以顺序是对的不会 RE。（快说谢谢 c++ 组委会强制规定了顺序）
# [P3740 [HAOI2014]贴海报](https://www.luogu.com.cn/problem/P3740)
## 题意
- 操作 $1$：区间推平颜色
- 结束时回答有几种颜色
## 做法
直接上珂朵莉，秒了。因为全是推平操作，所以复杂度上限 $\mathcal O(m\log m)$
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
}s;
bool b[1001];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	s.emplace(1,n,0),s.emplace(n+1,n+1,0);
	for(int i=1,l,r;i<=m;i++)cin>>l>>r,s.assign(l,r,i);
	for(auto it:s)b[it.val]=true;
	cout<<std::count(b+1,b+1+m,true);
	return 0;
}
```
# [P1558 色板游戏](https://www.luogu.com.cn/problem/P1558)
## 题意
- 操作 $1$：区间推平颜色
- 操作 $2$：求区间颜色数量
## 做法
操作 $1$ 照常推平，操作 $2$ 开个桶，从 $l$ 一个一个区间跑到 $r$ 去计算答案。可以被构造出很多单个区间然后每次对这些区间询问卡掉。（然而这题暴力都能过）
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
using std::cin;using std::cout;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	bool c[31];
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	int query(int l,int r){
		memset(c,0,sizeof c);
		for(auto ir=split(r+1),il=split(l);il!=ir;il++)c[il->val]=true;
		return (int)std::count(std::begin(c),std::end(c),true);
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,T,l,r,c;char t;cin>>n>>T>>T;
	s.emplace(1,n,1),s.emplace(n+1,n+1,0);
	while(T--)switch(cin>>t>>l>>r;t){
	case 'C':cin>>c;s.assign(std::min(l,r),std::max(l,r),c);break;
	case 'P':cout<<s.query(std::min(l,r),std::max(l,r))<<'\n';break;
	}
	return 0;
}
```
# [CF915E Physical Education Lessons](https://www.luogu.com.cn/problem/CF915E)
## 题意
- 操作 $1$：区间推平成 $0$
- 操作 $2$：区间推平成 $1$
- 每次操作完后询问 $1$ 的数量
## 做法
推平直接推平就行了。暴力统计答案的复杂度可以被卡，考虑直接维护总区间的答案，当一段 $0$ 变成 $1$ 后答案增加区间长度，$1$ 变成 $0$ 时在推平后答案减少区间长度即可做到 $\mathcal O(m\log m)$ 的正确复杂度。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
using std::cin;using std::cout;
int n,m,ans;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		auto ir=split(r+1),il=split(l);
		for(auto it=il;it!=ir;it=erase(it))ans+=(k-it->val)*(it->r-it->l+1);
		return emplace(l,r,k).first;
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;ans=n;s.emplace(1,n,1);s.emplace(n+1,n+1,0);
	for(int l,r,t;m--;)cin>>l>>r>>t,s.assign(l,r,t-1),cout<<ans<<'\n';
	return 0;
}
```
# [P5350 序列](https://www.luogu.com.cn/problem/P5350)
## 题意
- 操作 $1$：求 $a_l$ 到 $a_r$ 的和
- 操作 $2$：将 $a_l$ 到 $a_r$ 赋值为 $\mathrm{val}$
- 操作 $3$：将 $a_l$ 到 $a_r$ 加上$\mathrm{val}$
- 操作 $4$：将 $a_{l_1}$ 到 $a_{r_1}$ 复制到 $a_{l_2}$ 到 $a_{r_2}$ 处
- 操作 $5$：将 $a_{l_1}$ 到 $a_{r_1}$ 与 $a_{l_2}$ 到 $a_{r_2}$ 交换
- 操作 $6$：将 $a_l$到 $a_r$ 翻转
- 保证数据随机。
## 做法
珂朵莉直接按照题意模拟即可。因为数据是随机而且有推平操作可以保证珂朵莉的复杂度。操作 $1$ 和 $3$ 直接枚举区间，操作 $2$ 直接推平。其他操作可以把区间存到 `std::vector` 里慢慢搞。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define int long long
using std::cin;using std::cout;
constexpr int MOD=1e9+7;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	int query(int l,int r,int sum=0){
		auto ir=split(r+1),il=split(l);
		for(auto it=il;it!=ir;it++)sum+=(it->r-it->l+1)*it->val;
		return sum%MOD;
	}
	void add(int l,int r,int k){
		auto ir=split(r+1),il=split(l);
		for(auto it=il;it!=ir;it++){
			it->val+=k;
			if(it->val>=MOD)it->val-=MOD;
		}
	}
	void copy(int l1,int r1,int l2,int r2){
		int p=l2-l1;
		split(r2+1),split(l2);split(r1+1),split(l1);
		erase(lower_bound(l2),lower_bound(r2+1));
		for(auto it=lower_bound(l1);it->r<=r1;it++)emplace(it->l+p,it->r+p,it->val);
	}
	void swap(int l1,int r1,int l2,int r2){
		int p=l2-l1;
		std::vector<odt_node>t1,t2;
		auto ir=split(r2+1),il=split(l2);
		for(auto it=il;it!=ir;it++)t2.emplace_back(it->l,it->r,it->val);
		ir=split(r1+1),il=split(l1);
		for(auto it=il;it!=ir;it++)t1.emplace_back(it->l,it->r,it->val);
		erase(il,ir);
		for(auto it:t2)emplace(it.l-p,it.r-p,it.val);
		ir=split(r2+1),il=split(l2);
		erase(il,ir);
		for(auto it:t1)emplace(it.l+p,it.r+p,it.val);
	}
	void reverse(int l,int r){
		auto ir=split(r+1),il=split(l);
		std::vector<odt_node>t;
		for(auto it=il;it!=ir;it++)t.emplace_back(it->l-l,it->r-l,it->val);
		erase(il,ir);
		for(auto it:t)emplace(r-it.r,r-it.l,it.val);
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;s.emplace(n+1,n+1,0);
	for(int i=1,t;i<=n;i++)cin>>t,s.emplace(i,i,t);
	while(m--){
		int t,l,r,x,y,k;cin>>t;switch(t){
		case 1:cin>>l>>r;cout<<s.query(l,r)<<'\n';break;
		case 2:cin>>l>>r>>k;s.assign(l,r,k);break;
		case 3:cin>>l>>r>>k;s.add(l,r,k);break;
		case 4:cin>>l>>r>>x>>y;s.copy(l,r,x,y);break;
		case 5:cin>>l>>r>>x>>y;if(l>x)std::swap(l,x),std::swap(r,y);s.swap(l,r,x,y);break;
		case 6:cin>>l>>r;s.reverse(l,r);break;
		}
	}
	for(auto it:s)for(;it.l<=it.r&&it.r<=n;it.l++)cout<<it.val<<' ';
	return 0;
}
```
# [P2061 [USACO07OPEN]City Horizon S](https://www.luogu.com.cn/problem/P2061)
## 题意
平面上给出很多下底和 $x$ 轴平行的长方形，求这些长方形的面积并之和。
## 做法
将所有楼房的坐标和高度存下来，按照高度从小到大排序，然后按照坐标推平即可。因为楼房低的会被高的覆盖掉所以是正确的。复杂度是 $\mathcal O(n\log n)$
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define int long long
using std::cin;using std::cout;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
}s;
odt_node a[40001];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m2=-0x3f3f3f3f3f3f3f3f,ans=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r>>a[i].val,a[i].r--,m2=std::max(a[i].r,m2);
	std::sort(a+1,a+1+n,[](const auto &x,const auto &y){return x.val<y.val;});
	s.emplace(1,m2,0);s.emplace(m2+1,m2+1,0);
	for(int i=1;i<=n;i++)s.assign(a[i].l,a[i].r,a[i].val);
	for(auto it:s)ans+=(it.r-it.l+1)*it.val;
	cout<<ans;
	return 0;
}
```
# [ABC255H Range Harvest Query](https://atcoder.jp/contests/abc255/tasks/abc255_h)
## 题意
- 每天第 $n$ 颗树会长 $n$ 个果子
- 第 $d_i$ 天会收割第 $l_i$ 到 $r_i$ 棵树上的所有果子
- 输出每次收割的果子数量
- $n\le10^{18}$ $q\leq2\times10^5$
## 做法
考虑暴力珂朵莉，每次进行一次全局加法，然后把 $l_i$ 到 $r_i$ 的和乘上每棵树自己的贡献再把这段区间推平了，可以发现这种做法极其依赖随机数据，可以通过构造大量散区间卡到 $\mathcal O(q^2\log q)$ 的复杂度。考虑这种做法的复杂度瓶颈是每次询问之前的全局加，而全部都加等于全部都不加，所以应该只对 $l_i$ 到 $r_i$ 进行操作才能保证正确的复杂度（珂朵莉重要思想），所以考虑修改标记含义，每段区间的 $val$ 表示上一次采摘果子的时间，这样拿这次的时间减去上次的时间再乘上贡献最后全部加起来就是答案了。每次暴力区间后都会推平，每次推平最多 `split` 两次，每次 `split` 最多增加一段区间，$所以最多暴力 $q$ 个区间，每次是 $\mathcal O(\log q)$，所以复杂度是 $\mathcal O(q\log q)$ 是正确的。不要忘记多多取模哦~
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1,MOD=998244353;
constexpr int add0(int x,int y){return (x+=y)<MOD?x:x-MOD;}
constexpr int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
constexpr int sub0(int x,int y){return (x-=y)<0?x+MOD:x;}
constexpr int&sub1(int&x,int y){return (x-=y)<0?x+=MOD:x;}
constexpr int mul(const std::initializer_list<int>&x){loli y=1;for(int i:x)(y*=i)%=MOD;return int(y%MOD);}
constexpr int calc(int l,int r){return mul({add0(l,r),sub0(add0(r,1),l),499122177});}
struct odt_node{
	loli l,r;mutable int val;
	odt_node(loli a=0,loli b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(loli p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(loli l,loli r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	auto query(loli l,loli r,int k){
		int ans=0;
		for(auto ir=split(r+1),il=split(l);il!=ir;il++)
			add1(ans,mul({sub0(k,il->val),calc(int(il->l%MOD),int(il->r%MOD))}));
		assign(l,r,k);
		return ans;
	}
}s;
struct{loli l,r,val;}a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	loli n;int m;cin>>n>>m;
	s.emplace(1,n,0),s.emplace(n+1,n+1,0);
	for(int i=1;i<=m;i++)
		cin>>a[i].val>>a[i].l>>a[i].r,
		cout<<s.query(a[i].l,a[i].r,int(a[i].val%MOD))<<'\n';
	return 0;
}
```
# [ABC256H I like Query Problem](https://atcoder.jp/contests/abc256/tasks/abc256_h)
## 题面
- 操作 $1$：将 $a_l$ 到 $a_r$ 赋值为 $\lfloor\dfrac{a_i}x\rfloor$
- 操作 $2$：将 $a_l$ 到 $a_r$ 赋值为 $x$
- 操作 $3$：求 $\large\sum_{i=l}^ra_i$
## 做法
使用珂朵莉进行维护，操作 $1$ 进行时对相同的块进行合并，操作 $2$ 直接推平，操作 $3$ 暴力求和。这种做法可以被全是操作 $3$ 卡掉。使用树套树，在珂朵莉内维护一个线段树，每次操作 $1$ 之前对线段加上 $\dfrac{\lfloor v_\rfloor}x-v$，每次操作 $2$ 之前对线段加上 $x-v$，操作 $3$ 就可以直接使用线段树的询问了。复杂度是 $\mathcal O((n+m)\log n\log a_i)$
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=5e5+1;
int n,m,a[kN];
struct odt_node{
	int l,r;mutable int val;
	odt_node(int _a=0,int _b=0,int _c=0):l(_a),r(_b),val(_c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	struct sgt{
		struct{int li,ri;loli sum,tag;int num(){return ri-li+1;}}s[kN<<2];
#define ls (now*2)
#define rs (now*2+1)
#define mid ((s[now].li+s[now].ri)/2)
		auto build(int now,int l,int r){
			s[now].tag=0;s[now].li=l;s[now].ri=r;
			if(l==r){s[now].sum=a[l];return;}
			build(ls,l,mid);build(rs,mid+1,r);
			s[now].sum=s[ls].sum+s[rs].sum;
		}
		auto spread(int now){
			if(!s[now].tag)return;
			s[ls].sum+=s[now].tag*s[ls].num();
			s[rs].sum+=s[now].tag*s[rs].num();
			s[ls].tag+=s[now].tag;s[rs].tag+=s[now].tag;
			s[now].tag=0;
		}
		auto add(int now,int l,int r,loli k){
			if(l<=s[now].li&&s[now].ri<=r){s[now].sum+=k*s[now].num(),s[now].tag+=k;return;}
			spread(now);
			if(l<=mid)add(ls,l,r,k);
			if(r>mid)add(rs,l,r,k);
			s[now].sum=s[ls].sum+s[rs].sum;
		}
		auto query(int now,int l,int r,loli sum=0){
			if(l<=s[now].li&&s[now].ri<=r)return s[now].sum;
			spread(now);
			if(l<=mid)sum+=query(ls,l,r);
			if(r>mid)sum+=query(rs,l,r);
			return sum;
		}
#undef ls
#undef rs
#undef mid
	}sg;
	auto build(int r){sg.build(1,1,r);}
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		for(auto ir=split(r+1),il=split(l);il!=ir;++il)
			sg.add(1,il->l,il->r,k-il->val);
		erase(split(l),split(r+1));
		emplace(l,r,k);
	}
	auto div(int l,int r,int k){
		for(auto ir=split(r+1),il=split(l);il!=ir;++il)
			sg.add(1,il->l,il->r,il->val/k-il->val);
		for(auto ir=split(r+1),il=split(l);il!=ir;)for(auto jl=std::next(il);;++jl)
			if(jl==ir||il->val/k!=jl->val/k){
				odt_node t(il->l,std::prev(jl)->r,il->val/k);
				erase(il,jl);emplace(t);il=jl;break;
			}
	}
	auto query(int l,int r){return sg.query(1,l,r);}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;s.emplace(n+1,n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i],s.emplace(i,i,a[i]);
	s.build(n);
	for(int t,l,r,x;m--;){
		cin>>t>>l>>r;
		switch(t){
		case 1:cin>>x;s.div(l,r,x);break;
		case 2:cin>>x;s.assign(l,r,x);break;
		case 3:cout<<s.query(l,r)<<'\n';break;
		}
	}
	return 0;
}
```
---
求求了，真的找不好放点什么题，珂朵莉的操作无非也就这样，如果要加强难度无非也是别的 DS 套个珂朵莉，什么主席树值域分块都可以套上去，所以实在没什么题可以放了……其实珂朵莉也就这，基本可以被线段树和一堆 tag 吊着打，不用珂朵莉也可以用类似平衡树维护，珂朵莉唯一的优点就是好写。
放写可以珂朵莉做的但是我不太会做或者不太想做的：
- [CF1651F Tower Defense](https://www.luogu.com.cn/problem/CF1651F) 珂朵莉维护区间前驱耗竭的塔
- [P8146 [JRKSJ R4] risrqnis](https://www.luogu.com.cn/problem/P8146) 珂朵莉与值域分块