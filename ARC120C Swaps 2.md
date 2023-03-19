好难啊，会也不会

设 $a_i=x,a_{i+1}=y$，那么交换后 $a_i=y+1,a_{i+1}=x-1$，发现交换后就是 $a_i+i$ 和 $a_{i+1}+i+1$ 这两个值进行了交换。  
那就把所有 $a_i$ 变成 $a_i+i$，把所有 $b_i$ 变成 $b_i+i$，那就是进行最少的操作把 $a$ 变成 $b$，那就直接逆序对计算数量。  
注意，如果有相同的值，应该把这些放到 `queue` 中，让前面的和前面的去匹配，这样最优。
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
using std::cin;using std::cout;
using loli=long long;
constexpr bool ying=false,yang=true;
constexpr int N=4e5+1;
std::map<int,std::queue<int>>mp;
int n,a[N],b[N],c[N];
loli sum=0;
struct{
	int d[N];
	void add(int x){for(;x<=n;x+=x&-x)d[x]++;}
	loli ask(int x){loli k=0;for(;x;x-=x&-x)k+=d[x];return k;}
}tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]+=i,mp[a[i]].push(i);
	for(int i=1;i<=n;i++)
		cin>>b[i],b[i]+=i;
	for(int i=1;i<=n;i++)
		if(!mp.count(b[i]))return cout<<"-1",0;
		else c[i]=mp[b[i]].front(),mp[b[i]].pop();
	for(int i=1;i<=n;i++)
		sum+=i-1-tr.ask(c[i]),tr.add(c[i]);
	cout<<sum;
	return 0;
}
```