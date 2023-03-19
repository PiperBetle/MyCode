#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto&
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
constexpr int N=1e5+1;
int n;
std::string s[N];
std::set<std::string>mp;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--)cout<<[]{
		cin>>n;mp.clear();
		for(int i=1;i<=n;i++)cin>>s[i];
		for(int i=1;i<=n;i++){
			if(siz(s[i])==1)return "YES\n";
			else if(siz(s[i])==2){
				if(s[i][0]==s[i][1])return "YES\n";
				cauto t=std::string{s[i][1],s[i][0]};
				if(mp.count(t))return "YES\n";
				for(char c='a';c<='z';c++)if(mp.count(t+c))return "YES\n";
			}else{
				if(s[i][0]==s[i][2])return "YES\n";
				cauto t=std::string{s[i][2],s[i][1]};
				if(mp.count(t))return "YES\n";
				if(mp.count(t+s[i][0]))return "YES\n";
			}
			mp.insert(s[i]);
		}
		return "NO\n";
	}();
	return 0;
}