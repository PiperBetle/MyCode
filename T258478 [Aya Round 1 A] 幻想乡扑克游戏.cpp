#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
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
constexpr venti operator""_vt(uloli x){return venti(x);}
std::map<char,int>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		char c;
		s.clear();
		for(int i=1;i<=17;i++)cin>>c,s[c]++;
		if(s['X']+s['D']==2){cout<<"Yes\n";continue;}
		std::string ans="No";
		for(auto[x,y]:s)if(y>=4){ans="Yes";break;}
		cout<<ans<<'\n';
	}
	return 0;
}