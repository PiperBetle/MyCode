前景提要：以下所有珂朵莉的题**全部**保证珂朵莉的复杂度正确，以下所有 $n$ 表示序列长度，$q$ 表示操作次数。
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
直接上珂朵莉，秒了。因为全是推平操作，所以复杂度上限 $\mathcal O(q\log n)$
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
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
# [P2391 白雪皑皑](https://www.luogu.com.cn/problem/P2391)
## 题意v
直接推平会因为 $10^7$ 的 $\log$ 被超时，但是会发现只有后最后 $n$ 次操作有效，那就直接推平去吧！复杂度是 $\mathcal O(n\log n)$。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
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
		if(l>r)std::swap(l,r);
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
}s;
int n,m,p,q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>p>>q;
	s.emplace(1,n,0);s.emplace(n+1,n+1,0);
	for(int i=std::max(m/n*n-n,1);i<=m;i++)s.assign((i*p+q)%n+1,(i*q+p)%n+1,i);
	for(auto[l,r,k]:s)if(l<=n)for(;l<=r;l++)cout<<k<<'\n';
	return 0;
}
```
# [CF915E Physical Education Lessons](https://www.luogu.com.cn/problem/CF915E)
## 题意
- 操作 $1$：区间推平成 $0$
- 操作 $2$：区间推平成 $1$
- 每次操作完后询问 $1$ 的数量
## 做法
推平直接推平就行了。暴力统计答案的复杂度可以被卡，考虑直接维护总区间的答案，当一段 $0$ 变成 $1$ 后答案增加区间长度，$1$ 变成 $0$ 时在推平后答案减少区间长度即可做到 $\mathcal O(q\log n)$ 的正确复杂度。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
珂朵莉直接按照题意模拟即可。因为数据是随机而且有推平操作可以保证珂朵莉的复杂度。操作 $1$ 和 $3$ 直接枚举区间，操作 $2$ 直接推平。其他操作可以把区间存到 `std::vector` 里慢慢搞。复杂度只有 $\mathcal O(n\log n)$。
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
将所有楼房的坐标和高度存下来，按照高度从小到大排序，然后按照坐标推平即可。因为楼房低的会被高的覆盖掉所以是正确的。复杂度是 $\mathcal O(n\log n)$。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
#include<set>
using std::cin;using std::cout;
using loli=long long;
constexpr int N=2e5+1,MOD=998244353;
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
struct{loli l,r,val;}a[N];
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
使用珂朵莉进行维护，操作 $1$ 进行时对相同的块进行合并，操作 $2$ 直接推平，操作 $3$ 暴力求和。这种做法可以被全是操作 $3$ 卡掉。使用树套树，在珂朵莉内维护一个线段树，每次操作 $1$ 之前对线段加上 $\dfrac{\lfloor v_\rfloor}x-v$，每次操作 $2$ 之前对线段加上 $x-v$，操作 $3$ 就可以直接使用线段树的询问了。复杂度是 $\mathcal O((n+q)\log n\log a_i)$
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
using std::cin;using std::cout;
using loli=long long;
constexpr int N=5e5+1;
int n,m,a[N];
struct odt_node{
	int l,r;mutable int val;
	odt_node(int _a=0,int _b=0,int _c=0):l(_a),r(_b),val(_c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	struct sgt{
		struct{int li,ri;loli sum,tag;int num(){return ri-li+1;}}s[N<<2];
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
# [CF1705E Mark and Professor Koro](https://codeforces.com/problemset/problem/1705/E)
## 题面
- 给定一个二进制数，每次操作减去再加上一个二的幂，每次操作后输出最高位。
## 做法
可以采取珂朵莉去维护这个数，加法就相当于把后面一段连续的 $1$ 推平，在下一个位置放个 $1$。减法相当于把后面一段连续的 $0$ 推平成 $1$，在下一个位置放个 $1$。输出最高位直接从后向前遍历，同时推平连续段来保证复杂度即可。因为每次操作只会增加少量区间，暴力遍历的区间也会被推平，复杂度是 $\mathcal O(n\log n)$。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
constexpr int N=2.1e5+1;
struct odt_node{
	int l,r;mutable int v;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),v(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.v);
		return emplace(p,t.r,t.v).first; 
	}
	auto assign(int l,int r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	auto add(int p){
		split(p+1);auto it=split(p);
		if(!it->v){it->v=1;return;}
		int l=it->l;while(it->v)++it;int r=it->l-1;
		assign(l,r,0);split(r+2);split(r+1)->v=1;
	}
	auto sub(int p){
		split(p+1);auto it=split(p);
		if(it->v){it->v=0;return;}
		int l=it->l;while(!it->v)++it;int r=it->l-1;
		assign(l,r,1);split(r+2);split(r+1)->v=0;
	}
	auto query(){
		for(auto it=--end();;--it)
			if(it->v)return assign(it->r+1,rbegin()->r,0),it->r;
			else if(it==begin())return 0;
	}
}s;
int n,m,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;s.emplace(1,N,0);
	for(int i=1;i<=n;i++)cin>>a[i],s.add(a[i]);
	for(int x,y;m--;)cin>>x>>y,s.sub(a[x]),s.add(a[x]=y),cout<<s.query()<<'\n';
	return 0;
}
```
# [CF1638E Colorful Operations](https://codeforces.com/problemset/problem/1638/E)
## 题面
- 操作 $1$：将 $a_l$ 到 $a_r$ 颜色推平为 $c$
- 操作 $2$：将所有颜色 $c$ 加上 $x$
- 操作 $3$：求 $a_i$ 的值
## 做法
推平直接采用珂朵莉的推平，考虑颜色是所有颜色一起加的，那就为每个颜色维护一个加法 tag，那么操作 $1$ 在推平时加上原先的颜色 tag 再减去现在颜色的 tag，这个可以用一个树状数组去维护，在查询的时候输出这个点的值和这个颜色 tag 值的和即可。推平的区间数量是线性的（就相当于只有推平操作的珂朵莉，这种珂朵莉复杂度一定是正确的），树状数组带一个 $\log$，所以复杂度是 $\mathcal O(q(\log n+\log q))$。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using std::cin;using std::cout;
using loli=long long;
constexpr int N=1e6+1;
int n,q;
loli c[N];
std::string bb;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int _a=0,int _b=0,int _c=0):l(_a),r(_b),val(_c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	struct BIT{
		loli data[N]={};
		void add(int x,loli k=1){for(;x<=n;x+=x&-x)data[x]+=k;}
		loli query(int x){loli k=0;for(;x;x-=x&-x)k+=data[x];return k;}
		void updata(int l,int r,loli k){add(l,k);add(r+1,-k);}
	}bt;
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first; 
	}
	auto assign(int l,int r,int k){
		auto ir=split(r+1),il=split(l);
		for(auto it=il;it!=ir;it++)bt.updata(it->l,it->r,c[it->val]-c[k]);
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	auto &operator[](int k){split(k+1);return split(k)->val;}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;s.emplace(1,n,1);s.emplace(n+1,n+1,0);
	for(int x,y,z;q--;)switch(cin>>bb>>x;bb.front()){
	case 'C':cin>>y>>z;s.assign(x,y,z);break;
	case 'A':cin>>y;c[x]+=y;break;
	case 'Q':cout<<s.bt.query(x)+c[s[x]]<<'\n';break;
	}
	return 0;
}
```
# [P4979 矿洞：坍塌](https://www.luogu.com.cn/problem/P4979)
## 题面
- 操作 $1$：把 $[l,r]$ 推平成 $k$
- 操作 $2$：询问 $[l,r]$ 颜色是否相等且 $a_{l-1}$ 的颜色是否等于 $a_{r+1}$
## 做法
操作 $1$ 直接采用珂朵莉直接推平，操作 $2$ 可以先在 $\mathcal O(\log n)$ 判断 $a_{l-1}$ 和 $a_{r+1}$ 的颜色，对于 $[l,r]$ 的颜色直接暴力访问，在访问后把颜色相同的块并起来就行了，因为全是推平，所以复杂度是 $\mathcal O((n+q)\log n)$。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using std::cin;using std::cout;
using std::prev;using std::next;
struct odt_node{
	int l,r;mutable char val;
	odt_node(int a=0,int b=0,char c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
int n,q,pre=1;
char c1,c2;
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first; 
	}
	auto assign(int l,int r,char k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	bool query(int l,int r){
		auto ir=split(r+1),il=split(l);
		if(l!=1&&r!=n&&prev(il)->val==ir->val)return false;
		for(auto it=il;it!=ir;++it)if(il->val!=it->val)
			return assign(il->l,(--it)->r,il->val),false;
		return assign(l,r,il->val),true;
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>c2;
	for(int i=2;i<=n;i++){
		cin>>c1;
		if(c1!=c2)s.emplace(pre,i-1,c2),pre=i;
		c2=c1;
	}
	s.emplace(pre,n,c1);
	s.emplace(n+1,n+1,'D');
	cin>>q;
	for(int l,r;q--;){
		char op,k;cin>>op;
		if(op=='A')cin>>l>>r>>k,s.assign(l,r,k);
		else cin>>l>>r,cout<<(s.query(l,r)?"Yes\n":"No\n");
	}
	return 0;
}
```
# [CF1690G Count the Trains](https://codeforces.com/problemset/problem/1690/G)
## 题面
给定一辆火车，给定每个车厢的最大速度，要求每个车厢的速度不得大于前一个。
- 操作 $1$：把第 $x$ 节车厢速度减少 $k$
每次操作后输出连续段个数
## 做法
和上一题做法相同，每次修改后向后尽量合并就行了。复杂度是 $\mathcal O((n+q)\log n)$。
## 代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int N=1e5+1,inf=0x3f3f3f3f;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
int n,m,a[N];
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first; 
	}
	auto updata(int l,int k){
		auto il=split(l);
		if((a[l]-=k)>=il->val)goto pblk;
		else il->val=a[l];	
		for(auto it=std::next(il);;++it){
			if(it->val<il->val){
				int t=il->val;
				erase(il,it);
				emplace(l,it->l-1,t);
				goto pblk;
			}
		}
		pblk:il=lower_bound(l);
		if(il!=--end()&&il->val==std::next(il)->val){
			int l=il->l,r=std::next(il)->r,t=il->val;
			erase(std::next(il));erase(il);
			emplace(l,r,t);
		}
		il=lower_bound(l);
		if(il!=begin()&&il->val==std::prev(il)->val){
			int l=std::prev(il)->l,r=il->r,t=il->val;
			erase(std::prev(il));erase(il);
			emplace(l,r,t);
		}
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;
		s.clear();
		int j=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<a[j])s.emplace(j,i-1,a[j]),j=i;
		}
		s.emplace(j,n,a[j]);s.emplace(n+1,n+1,-inf);
		for(int x,k;m--;){
			cin>>x>>k;
			s.updata(x,k);
			cout<<siz(s)-1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
```
---
求求了，真的找不好放点什么题，珂朵莉的操作无非也就这样，如果要加强难度无非也是别的 DS 套个珂朵莉，什么主席树值域分块都可以套上去，所以实在没什么题可以放了……其实珂朵莉也就这，基本可以被线段树和一堆 tag 吊着打，不用珂朵莉也可以用类似平衡树维护，珂朵莉唯一的优点就是好写（特别好写）。
放写可以珂朵莉做的但是我不太会做或者不太想做的：
- [CF1651F Tower Defense](https://www.luogu.com.cn/problem/CF1651F) 珂朵莉维护区间前驱耗竭的塔
- [P8146 [JRKSJ R4] risrqnis](https://www.luogu.com.cn/problem/P8146) 珂朵莉与值域分块