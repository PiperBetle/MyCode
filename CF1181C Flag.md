题意：问在一个 $n\times m$ 的平面里有多少旗帜，旗帜的定义是三条宽度相等的带子，相邻的带子颜色不能相同（第一和第三条的颜色可以相同）。

考虑以左上角统计旗帜，预处理每个点向下走遇到颜色不同的点的距离记为 $d=f_{i,j}$，设当前的点颜色为 $a_{i,j}$，那么必须满足 `f[i+d][j]==d&&f[i+2*d][j]>=d&&a[i][j]!=a[i+d][j]&&a[i+d][j]!=a[i+2*d][j]`，`f[i+d][j]==d` 是为了确保第一和第二条的宽度相等，`f[i+2*d][j]>=d` 是为了保证第三条的宽度至少是第一第二条的宽度，至于 `a[i][j]!=a[i+d][j]&&a[i+d][j]!=a[i+2*d][j]` 是为了保证第一和第二条，第二和第三条的颜色不同。  
现在只是确定了向下的方向，固定左上角的点，第二第三条的颜色与宽度是确定的，但是向右延申的距离是不知道的，比如这个（蓝粉白粉蓝<img src="https://img2022.cnblogs.com/blog/2192761/202211/2192761-20221117162606892-1705944873.png" style="zoom:5%"/>）：
```
BBBBBBBBBB
PPPPPPPPPP
WWWWWWWWWW
PPPPPPPPPP
BBBBBBBBBB
```
在枚举到 $(1,1)$ 这个点时，已经确定每条的高度是 $1$ 并且颜色是 $\text{B,P,W}$ 但是没法快速统计出右边能延申几个，不妨把贡献挂在右边的节点上，比如 $(1,1)$ 的贡献是 $1$，$(1,2)$ 的贡献是 $2$，$(1,3)$ 的贡献是 $3$，这样就很好办了。  
记录往下是否可行为条件 $1$，和左边是否一样为条件 $2$，因为要枚举每个点，先枚举行，在枚举列时记录一个 $k$，如果不满足条件 $1$ 那么 $k=0$，否则进行判断，如果这三带和前面那一带一模一样，也就是 `f[i][j-1]==d&&f[i+d][j-1]==d&&f[i+2*d][j-1]>=d&&a[i][j-1]==a[i][j]&&a[i+d][j-1]==a[i+d][j]&&a[i+2*d][j-1]==a[i+2*d][j]` 那么就 $k=k+1$，否则 $k=1$，执行完操作后 $ans=ans+k$ 就行了。

代码：
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
using std::cin;using std::cout;
using loli=long long;
constexpr int N=1002;
int n,m,f[N][N];
char a[N][N];
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=n;i>=1;i--)for(int j=1;j<=m;j++)
		if(a[i][j]==a[i+1][j])f[i][j]=f[i+1][j]+1;else f[i][j]=1;
	for(int i=1;i<=n;i++)for(int j=1,k=0;j<=m;j++){
		int d=f[i][j];
		if(i+3*d-1<=n&&f[i+d][j]==d&&f[i+2*d][j]>=d&&a[i][j]!=a[i+d][j]&&a[i+d][j]!=a[i+2*d][j]){
			if(f[i][j-1]==d&&f[i+d][j-1]==d&&f[i+2*d][j-1]>=d&&a[i][j-1]==a[i][j]&&a[i+d][j-1]==a[i+d][j]&&a[i+2*d][j-1]==a[i+2*d][j])
				k++;
			else k=1;
		}else k=0;
		ans+=k;
	}
	cout<<ans;
	return 0;
}
```