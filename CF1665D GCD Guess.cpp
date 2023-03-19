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
using std::cin;using std::cout;using std::endl;
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
		unsigned x=0;
		auto query=[&](unsigned a,unsigned b){cout<<"? "<<a-x<<' '<<b-x<<endl;unsigned t;cin>>t;return t;};
		auto answer=[&]{cout<<"! "<<x<<endl;};
		for(int i=0;i<30;i++)if(query(1u<<i,3u<<i)==2u<<i)x|=1u<<i;
		answer();
	}
	return 0;
}