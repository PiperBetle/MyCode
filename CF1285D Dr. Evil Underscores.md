给定一个序列 $a$，选取一个 $x$，使 $\max_{i=1}^na_i\oplus x$ 最小。

看到这种题直接按位考虑，如果最高位全是 $1$ 那把 $x$ 的这位全变成 $1$，如果最高位全是 $0$ 那把 $x$ 的这位全变成 $0$。如果有 $0$ 有 $1$，$x$ 的这一位不管怎么取 $\max_{i=1}^na_i\oplus x$ 都要算上 $2^k$，对于下一位就按照这位取 $0$ 还是 $1$ 去分治，取较小的就行了。因为最多递归 $\log w$ 次，每层需要 $\mathcal O(n)$，所以复杂度是 $\mathcal O(n\log w)$。
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
using std::max;using std::min;
using bsi=std::basic_string<int>;
constexpr int N=1e5+1;
int solve(const bsi &a,int k){
	if(a.empty()||k<0)return 0;
	bsi b1,b2;
	for(int i:a)(i>>k&1?b1:b2)+=i;
	if(b1.empty())return solve(b2,k-1);
	if(b2.empty())return solve(b1,k-1);
	return 1<<k|min(solve(b1,k-1),solve(b2,k-1));
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;bsi a;
	cin>>n;a.resize(n);
	for(int&i:a)cin>>i;
	cout<<solve(a,29);
	return 0;
}
```
关于 `basic_string` 和 `vector`，`basic_string` 的各种操作更快，但是空间消耗是 $32$，而 `vector` 只需要 $24$。