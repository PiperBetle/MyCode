似乎都是用拓扑排序做的？这里给出一个暴力做法但是复杂度正确。  
注意到 $n\le 1000$，考虑一种最暴力的写法，每一次对所有人进行查找比赛是否能进行，如果每次都可以所有人进行比赛，要进行 $n$ 次，复杂度是$\mathcal O(n)$，但是要是每天只有两个人能够进行比赛，复杂度是 $\mathcal O(n*\dfrac{n*(n-1)}2)$ 也就是 $\mathcal O(n^3)$ 的可以被构造特殊数据卡掉，所以要考虑复杂度正确的暴力。  
考虑这么一个性质，如果目前是第 $i$ 天，那么第 $i$ 天参加比赛的人一定至少有一个人在第 $i-1$ 天参加了比赛。证明：如果没有表示这两天的比赛是互不干扰的，互不干扰表示可以在同一天进行，所以在暴力枚举是会在第 $i-1$ 天处理掉的。  
也就是说可以在每次记录昨天参加比赛的人，在今天枚举的时候只需要枚举昨天参加比赛的人就可以了。至于判断一个人是否可行，只需要记录这个人指向的目标指向的目标是不是自己就可以了，写指针很方便而且很快，但是可能两个人都互相枚举到了，所以要去重。  
关于时间复杂度：考虑每次能解决 $w$ 次比赛，总共要进行 $\dfrac{n^2}w$ 天的比赛，每天比赛计算的复杂度是 $\mathcal O(w)$，那么复杂度是 $\mathcal O(\dfrac{n^2}w w)$ 也就是 $\mathcal O(n^2)$，不过我用了快速排序去重所以复杂度是 $\mathcal O(n^2\log w)$，实测因为常数小比用 `unordered_set` 写的去重快。  

~~快读很长所以放链接里了~~code：
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define autque(a) std::sort(a.begin(),a.end());a.erase(std::unique(a.begin(),a.end()),a.end())
// 快读在 https://www.cnblogs.com/bxjz/p/piper_add.html
constexpr int kN=1e3+1;
int n,k,cnt,f[kN][kN],*nw[kN];
using pii=std::pair<int,int>;
std::basic_string<int>lt;
std::vector<pii>wl;
signed main(){
//	freopen("plan.in","r",stdin);
//	freopen("plan.out","w",stdout);
	fio>>n;cnt=n*(n-1)/2;
	for(int i=1;i<=n;i++){
		lt+=i;
		for(int j=1;j<n;j++)fio>>f[i][j];
		nw[i]=f[i]+1;
	}
	for(k=0;cnt;k++){
		if(lt.empty())return fio<<"-1",0;
		for(int i:lt)if(i==*nw[*nw[i]])wl.emplace_back(std::minmax(i,*nw[i]));
		lt.clear();autque(wl);
		for(pii it:wl){
			int i=it.first,j=it.second;
			nw[i]++,nw[j]++;
			if(nw[i]<f[i]+n)lt+=i;
			if(nw[j]<f[j]+n)lt+=j;
			cnt--;
		}
		wl.clear();
	}
	fio<<k;
	return 0;
}
```
介绍一个函数：`std::minmax`，后面放两个参数或者 `std::initializer_list`，返回值是一个 `std::pair`，`.first` 表示较小的数，`.second` 表示较大的数。程序里使用是防止 $(3,1)(1,3)$ 这种情况不被去重。