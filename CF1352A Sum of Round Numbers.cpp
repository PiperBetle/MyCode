#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		std::string s;cin>>s;
		cout<<s.size()-std::count(all(s),'0')<<'\n';
		for(int i=0;i<siz(s);i++){
			if(s[i]=='0')continue;
			cout<<s[i];
			for(int j=i+1;j<siz(s);j++)cout<<'0';
			cout<<' ';
		}
		cout<<'\n';
	}
	return 0;
}