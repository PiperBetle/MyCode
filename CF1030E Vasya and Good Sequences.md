题意：给定一个序列，你可以对每个数字二进制位上的 $1$ 进行任意排布，问有多少子串满足异或和为 $0$。  
因为可以任意排布，所以只需要保留二进制下 $1$ 的数量即可。满足异或和为 $0$，就要保证这个子串的二进制下 $1$ 的数量之和为偶数，才能让每一个 $1$ 相互抵消。另外，最多的那个 $1$ 的数量不能超过子串二进制下 $1$ 的数量之和的一半，因为不能把最大的数的 $1$ 移动到别的数上，这样无法抵消全部的 $1$。  
如果只考虑偶数，直接枚举每个子串的复杂度是 $\mathcal O(n^3)$ 的，切换枚举顺序可以到 $\mathcal O(n^2)$，采用前缀和可以到 $\mathcal O(n)$。前缀和优化的意思是如果 $\sum_{i=1}^np_i$ 和 $\sum_{j=1}^np_j$ 在模 $2$ 意义下同余，那么 $\sum_{k=i+1}^jp_k$ 模 $2$ 一定是 $0$，$[i+1,j]$ 就满足了偶数的性质，开个记录前缀余数的桶扫一遍就行了。  
但是还要考虑最大不超过一半这个限制，题目保证 $a_i\ge1$ 也就是说每个数的二进制下 $1$ 的数量至少是 $1$，又因为 $a_i\le 10^{18}$，每个数的二进制下 $1$ 的数量最多才 $59$，只需要枚举所有长度小于 $60$ 的子串，如果这个子串的二进制下 $1$ 的数量正好是偶数并且满足最大超过一半，那么就把答案减去 $1$ 即可，长度大于等于 $60$ 的子串，就算一个数拉满二进制下 $1$ 的数量是 $59$，别的数摆烂是 $1$，也是符合要求的。
复杂度根据 `__builtin_popcount` 的实现，复杂度是 $\mathcal O(60n+n\log\log w)$ 到 $\mathcal O(60n)$。  
放个代码：（感觉比题解里的简短）
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=3e5+1;
int n,a[kN],cnt[]={1,0},sum;
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){loli x;cin>>x;a[i]=__builtin_popcountll(x);}
	for(int l=1;l<=n;l++){
		ans+=cnt[(sum+=a[l])&1]++;
		for(int r=l,max=0,num=0;r<=std::min(n,l+58);r++)
			max=std::max(max,a[r]),
			ans-=(num+=a[r])%2==0&&2*max>num;
	}
	cout<<ans;
	return 0;
}
```