简要题意：你有一张信用卡，$n$ 天有 $n$ 个操作，每次操作给定一个 $x$，如果 $x$ 是 $0$ 那么银行会查询信用卡里的金额，要保证金额是非负数；否则你卡里的金额会变化 $x$。每天操作前你可以在卡里存入任意多的钱，你要输出的是最小存钱次数，若无解输出 $-1$。另外，无论何时你卡里的金额不得超过 $m$。

因为前后充钱对于之后的操作并没有影响，而对于信用卡的余额是有上下界要求的，所以可以在操作的时候记录 `s1` 和 `s2` 表示当前信用卡里钱的下界和上界。  
具体来说，每次金额变化的时候把 `s1` 和 `s2` 都加上 $x$，由于 `s1` 是下界，如果下界都比 $m$ 大那肯定无解，如果上界比 $m$ 大把上界改为 $m$。如果是银行查询，下界小于 $0$ 直接修改为 $0$，上界小于 $0$ 直接修改为 $m$。  
代码：
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
constexpr int N=1e5+1;
int n,m,a[N],ans,s1,s2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)
		if(cin>>x,x){
			if((s1+=x)>m)return cout<<"-1",0;
			if((s2+=x)>m)s2=m;
		}else{
			if(s1<0)s1=0;
			if(s2<0)s2=m,ans++;
		}
	cout<<ans;
	return 0;
}
```