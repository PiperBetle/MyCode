题意：给一个长度为 $n$ 的 01 字符串，要让这个字符串的每个 1 之间的距离恰好都为 $k$，请问至少要修改几个字符。  

这里给出一种贪心做法：考虑一种万能方案，将所有字符串全部改成 0，这样就不会出现两个 1 之间的距离不是 $k$ 的情况，如果这么做修改数量就是字符串中 1 的个数。这里介绍一个 `std` 命名空间的函数 `std::count`，可以在线性时间内统计某个量的数量。~~但是用 for range 循环写法更短~~。

```cpp
for(i=0;i<s.length();i++)if(a[i]=='1')sum++;
for(auto it:s)if(it=='1')sum++;
sum=std::count(s.begin(),s.end(),'1');
```
接下来继续分析，发现所有 1 的出现肯定是聚在一起，不可能出现 2 段这种情况，否则就会不满足题意。考虑枚举第一个区间的位置 $i=[0,k-1]$，每次将指针 $j$ 右移 $k$ 位。如果 $s_j$ 是 0，那么必须变成 1，即 `cnt++`，否则代表刚刚 1 的数量多数了，即 `cnt--`，每次指针移动后与 $ans$ 取较小值，这样所有从最左端开始的区间就枚举完毕了。

但是还有以中间开始的情况，可以认为像前缀和一样，一条长区间割掉一条短区间。（~~你不会以为我要讲 dp 了吧~~）所以在每次指针转移时还有另一种方法：对之前进行的所有改变不作改变，即 `cnt=0` 。这样所有情况都会被考虑到。

~~还是代码~~
```cpp
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
std::string s;
using std::cin;using std::cout;
template<typename any>inline any min(any x,any y){return x<y?x:y;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m,T;
	cin>>T;
	while(T--){
		cin>>n>>m>>s;
		int sum=std::count(s.begin(),s.end(),'1'),ans=0x3f3f3f3f,cnt;
		for(i=0;i<m;i++)for(cnt=0,j=i;j<n;j+=m)
			cnt=min(s[j]=='1'?cnt-1:cnt+1,0),
			ans=min(ans,sum+cnt);
		cout<<ans<<'\n';
	}
	return 0;
}
```
关于时间复杂度：我自己测出来的结果比 dp 快不少。因为 $T$ 组数据最外层循环做 $T$ 次，中层循环 $k$ 次来枚举左端点，内层循环 $\dfrac{|s|}{k}$，全部乘起来就是 $O(T|s|)$ 和 dp 一模一样但是不仅不用 $f_{i,j}$ 而且常数很小自然而然比 dp 快了。