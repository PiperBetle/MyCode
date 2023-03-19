//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
#define all(x) std::begin(x),std::end(x)
#define break(x...) {x;break;}
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
	for(auto[k1,k2]:b1)
		if(s1<=k1)break(c1+=k1*s1)
		else c1+=k1*k2,s1-=k1;
	for(auto[k1,k2]:b2)
		if(s2<=k1)break(c2+=k1*s2)
		else c2+=k1*k2,s2-=k1;
	
	cout<<ans-min(c1,c2);
	return 0;
}