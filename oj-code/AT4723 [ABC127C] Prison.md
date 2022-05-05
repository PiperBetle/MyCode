这题我一看见还没反应过来， $10^5$ 的数据显然是要线段树等数据结构……？  
题意是给出一些集合，求出所有这些集合的交集的元素数量。考虑使用线段树，一开始将所有点赋值为 $n$ ，每次将区间 $[l,r]$ 全部减 $1$ 最后统计等于 $n$ 的元素个数，也就是说其实可以写差分树状数组区间修改，最后执行 $n$ 次单点查询，复杂度正确！  
但是我刚开始没想到树状数组的写法（直到看了题解），于是我想到了伟大的珂朵莉树，珂朵莉数可以实现区间推平操作，但是这题直接对区间 $[l,r]$ 操作不容易写，考虑逆向思维，一开始将所有点变为 $1$ ，对于区间 $[l,r]$ 变成将区间 $[1,l-1]$ 和 $[r+1,n]$ 变成 $0$ ，最后统计 $1$ 的数量即可。  
一般情况下珂朵莉树只能跑随机数据，但是这题没法卡珂朵莉树因为每一次操作都是推平操作，复杂度就是 $O(n\log n)$ 。  
板子题也贴个代码吧：
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
struct odt{
	int l,r;mutable int data;
	bool operator<(const odt &n)const{return l<n.l;}
};
std::set<odt>s;
inline auto split(int pos){
	auto it=s.lower_bound(odt{pos,-1,0});
	if(it!=s.end()&&it->l==pos)return it;
	it--;int l=it->l,r=it->r,t=it->data;
	s.erase(it);s.insert(odt{l,pos-1,t});
	return s.insert(odt{pos,r,t}).first;
}
inline void assign(int l,int r,int k){
	auto it_r=split(r+1),it_l=split(l);
	s.erase(it_l,it_r);
	s.insert(odt{l,r,k});
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;
	s.insert(odt{1,n,1});
	s.insert(odt{n+1,n+1,0});
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,assign(1,x-1,0),assign(y+1,n,0);
	for(auto it:s)ans+=(it.r-it.l+1)*it.data;
	cout<<ans;
	return 0;
}
```