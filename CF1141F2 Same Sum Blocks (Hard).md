简要题意：从一个序列里选出尽可能多的互不相交子串，使得所有子串的和相等并且使子串的数量最多，输出那些子串。

发现 $n\le1500$ 所以直接弄出所有子串，可以把子串按和扔到 `map` 里，每次就只要从里面选尽可能多的不相交的就行了。  
选出尽可能多的不相交的子串可以采取贪心，按照右端点从小到大，能选就选就行了。  
复杂度是 $\mathcal O(n^2\log n^2)=\mathcal O(n^2\log n)$。

代码：
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<random>
#include<map>
#include<ranges>
namespace vw=std::views;
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define fi first
#define se second
#define continue(x...) {x;continue;}
using std::cin;using std::cout;
using pii=std::pair<int,int>;
constexpr bool ying=false,yang=true;
constexpr int N=1501;
std::map<int,std::vector<pii>>mp;
int n,a[N];
std::vector<pii>ans,res;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=i,k=0;j<=n;j++)
		mp[k+=a[j]].emplace_back(i,j);
	for(auto&b:mp|vw::values){
		res.clear();
		sort(all(b),[](const pii &x,const pii &y){return x.se<y.se;});
		for(auto[l,r]:b)if(res.empty()||l>res.back().se)
			res.emplace_back(l,r);
		if(siz(res)>siz(ans))swap(ans,res);
	}
	cout<<siz(ans)<<'\n';
	for(auto[l,r]:ans)cout<<l<<' '<<r<<'\n';
	return 0;
}
```
代码里有个 `|vw::values` 可能不知道是什么意思，可以看我这篇[文章](https://www.cnblogs.com/bxjz/p/ranges.html)。