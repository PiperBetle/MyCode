#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
using std::cin;using std::cout;
using pii=std::pair<int,int>;
constexpr int kN=501;
std::set<pii>s;
pii a[kN];
int n;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(i==j)continue;
		pii d{a[i].first-a[j].first,a[i].second-a[j].second};
		int g=std::__gcd(abs(d.first),abs(d.second));
		s.emplace(d.first/g,d.second/g);
	}
	cout<<s.size();
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}