#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2001;
int n,a[N];
std::multiset<int>s;
std::vector<pii>ans;
bool check(int p){
	ans.clear();
	s.clear();
	s.insert(a+2,a+1+n*2);
	s.erase(s.find(a[p]));
	int x=a[1];
	ans.emplace_back(x,a[p]);
	for(int i=2;i<=n*2;i++){
		if(s.find(a[i])==s.end())continue;
		s.erase(s.find(a[i]));
		if(s.find(x-a[i])==s.end())return false;
		ans.emplace_back(a[i],x-a[i]);
		s.erase(s.find(x-a[i]));
		x=a[i];
	}
	return true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n*2;i++)cin>>a[i];
		std::sort(a+1,a+1+n*2,std::greater<int>());
		[]{
			for(int i=2;i<=n*2;i++)if(check(i)){
				cout<<"YES\n"<<ans[0].fi+ans[0].se<<'\n';
				for(auto[x,y]:ans)cout<<x<<' '<<y<<'\n';
				return;
			}
			cout<<"NO\n";
		}();
	}
	return 0;
}