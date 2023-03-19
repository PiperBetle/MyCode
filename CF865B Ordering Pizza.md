简要题意：有 $n$ 个人去披萨店吃披萨，有两种披萨，每个披萨有 $m$ 片。现在第 $i$ 个人要吃 $c_i$ 片披萨，如果吃一片第一种披萨会获得 $a_i$ 的幸运值，如果吃一片第二种披萨会获得 $b_i$ 的幸运值。现在需要购买最少数量的披萨使得每个人都吃饱并且所有人获得的幸运值之和最大。

贪心，如果一个人吃第一种披萨幸运值更高就让他只吃第一种披萨，吃第二种披萨幸运值更高就让他只吃第二种披萨，这样就能使幸运值之和最大了。  
不过有个问题，这样无法保证买最少的披萨。比如说一个披萨是 $5$ 片，第一种披萨买了 $6$ 片，第二种披萨买了 $7$ 片，总共买了 $4$ 个披萨，但实际上买 $3$ 个披萨就够了。把买第一种披萨比整个多出的数量记作 $s1$，买第二种披萨比整个多出的数量记作 $s2$，若 $s1+s2>m$，代表没办法买更少的披萨惹。  
否则按照吃两种披萨获得的幸运值之差从小到大排序，按照幸运值之差从小到大排序可以保证失去的幸运值最小，把多出来的那些减掉，也就是在吃第一种披萨中把 $s1$ 个人改成吃第二种披萨，或者在吃第二种披萨中把 $s2$ 个人改成吃第一种披萨，两种方案取更优的就行了。

代码：
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
#define all(x) std::begin(x),std::end(x)
using std::cin;using std::cout;
using std::max;using std::min;
using loli=long long;
using pii=std::pair<int,int>;
int n,m,s1,s2,c1,c2,ans;;
std::vector<pii>b1,b2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int c,a,b;n--;)if(cin>>c>>a>>b,a>b){
		ans+=a*c;
		b1.emplace_back(a-b,c);
		s1+=c;
	}else{
		ans+=b*c;
		b2.emplace_back(b-a,c);
		s2+=c;
	}
	s1%=m;s2%=m;
	if(s1+s2>m)return cout<<ans,0;
	sort(all(b1));
	sort(all(b2));
	for(auto[k1,k2]:b1){
		c1+=min(k2,s1)*k1;
		s1-=min(k2,s1);
		if(s1<=0)break;
	}
	for(auto[k1,k2]:b2){
		c2+=min(k2,s2)*k1;
		s2-=min(k2,s2);
		if(s2<=0)break;
	}
	cout<<ans-min(c1,c2);
	return 0;
}
```