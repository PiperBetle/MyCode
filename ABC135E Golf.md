[一道](https://atcoder.jp/contests/abc135/tasks/abc135_e)~~还行的~~构造题。  
题目大意：一开始你在初始点 $(0,0)$，每次可以跳的曼哈顿距离为 $k$，输出抵达 $(x,y)$ 跳的最少次数并且输出方案。  
首先发现 $x$ 和 $y$ 可正可负，不如把 $x$ 和 $y$ 都取绝对值，在之后输出时携带符号输出即可。  
因为每次的操作相当于把 $k$ 瓜分成 $x$ 和 $y$。先考虑如果 $k$ 是奇数那么只能拆成奇数和偶数，可以通过调控 $k$ 的数量来构造答案。如果 $k$ 是偶数 $x+y$ 是偶数，只要把 $k$ 拆成两个偶数或者奇数也是能做到的。只有 $k$ 是偶数并且 $x+y$ 是奇数时无解。  
设答案为 $n$，在 $x$ 轴和 $y$ 轴上的正向移动距离为 $a$，反向移动距离为 $b$，那么 $x+y\le n\times k$ 且 $(n\times k-x-y)\mod2=0$，这个不好解，但是 $x$ 和 $y$ 值域不大所以直接枚举 $n$ 的值就行。$a+b=n\times k$，$a-b=x+y$ 解出 $a=\dfrac{n\times k+x+y}2$，$b=\dfrac{n\times k-x-y}2$。
那就直接考虑在前进时的 $3$ 个情况即可：（这里的 $b$ 会随着逆向移动的距离而减小）
- $b\gt k$，选择 $x$ 和 $y$ 里当前位置距离最终位置比较近的一个，逆向移动 $k$。
- $b\leq k$，选择 $x$ 和 $y$ 里当前位置距离最终位置比较近的一个，逆向移动 $b$，另一个移动 $k-b$。
- $b=0$，任意把 $x$ 和 $y$ 推进，最艰难的时候过去了，可以随便放保证了。

放个代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
int n=2,k,x,y;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>k>>x>>y;
	int opx=x/abs(x),opy=y/abs(y);x*=opx,y*=opy;
	if(x+y==k)return cout<<"1\n"<<x*opx<<' '<<y*opy,0;
	if(k%2==0&&(x+y)%2==1)return cout<<"-1",0;
	for(;n*k<x+y||(n*k-x-y)%2;)n++;
	cout<<n<<'\n';
	int b=(n*k-x-y)/2;
	for(int nx=0,ny=0;n--;cout<<nx*opx<<' '<<ny*opy<<'\n')
		if(b){
			if(b>=k){if(x-nx<y-ny)nx-=k;else ny-=k;b-=k;}
			else{if(x-nx<y-ny)nx-=b,ny+=k-b;else ny-=b,nx+=k-b;b=0;}
		}else{if(nx<x){if(x-nx>=k)nx+=k;else ny+=k-x+nx,nx=x;}else ny+=k;}
	return 0;
}
```