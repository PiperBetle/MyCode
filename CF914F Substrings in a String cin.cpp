#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<bitset>
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
constexpr int kN=1e5+1;
std::bitset<kN>s[26],res;
std::string a,b;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	a.reserve(kN),b.reserve(kN);
	cin>>a;
	for(size_t i=0;i<a.size();i++)s[a[i]-'a'][i+1]=true;
	int T;cin>>T;while(T--){
		int t;cin>>t;if(t==1){
			int p;char c;cin>>p>>c;
			s[a[p-1]-'a'][p]=false;
			s[c-'a'][p]=true;
			a[p-1]=c;
		}else{
			int l,r;cin>>l>>r>>b;
			res.set();
			for(size_t i=0;i<b.size();i++)res&=(s[b[i]-'a']>>i);
			auto ans1=(res>>l).count(),ans2=(res>>(r+2-b.size())).count();
			cout<<(ans1<ans2?0:ans1-ans2)<<'\n';
		}
	}
	return 0;
}