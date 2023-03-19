无解的情况：当且仅当一个人手上的物品不是自己的物品，并且这个物品的质量大于自己的体重，这个不是自己的东西就卡手了，换不出去，无解。  
甲手上是乙的物品。乙的手上是丙的物品，丙的手上是丁的物品，丁的手上是甲的物品，那么甲乙丙丁就形成了一个环，置换环。由于每个人手上的物品（即 $p_i$）是个排列，所以原序列肯定可以划分为多个置换环，那么只要思考对于每个置换环怎么做就行了。  
找到环内体重最大的，然后按照环的顺序每次把下一个人和体重最大的交换手中的物品就行了。  
在这个交换过程中会不会出现卡手的情况呢？除去体重最大的那个人，环内的其他人都只交换了一次。如果一次都不能交换已经判定过了。而体重最大的如果会卡手，那这个物品是比环内所有人的体重都大的，而这种情况也判定过了。所以无解的情况只有一种。
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define siz(x) int((x).size())
#define all(x) std::begin(x),std::end(x)
using std::cin;using std::cout;
using pii=std::pair<int,int>;
using bsi=std::basic_string<int>;
constexpr int N=200001;
int n,a[N],b[N],p[N];
bool t[N];
bsi r;
std::vector<pii>ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)
		if(cin>>p[i],p[i]!=i&&b[p[i]]>=a[i])
			return cout<<"-1",0;
	for(int i=1;i<=n;i++)if(!t[i]){
		r.clear();
		for(int j=i;!t[j];j=p[j])
			t[j]=true,r+=j;
		int k=*max_element(all(r),[](int x,int y){
			return a[x]<a[y];});
		for(int j=k;p[j]!=k;j=p[j])
			ans.emplace_back(k,p[j]);
	}
	cout<<siz(ans)<<'\n';
	for(auto[u,v]:ans)cout<<u<<' '<<v<<'\n';
	return 0;
}
```