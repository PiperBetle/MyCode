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
	int T;cin>>T;for(int n0,n1,n2;T--;cout<<'\n'){
		cin>>n0>>n1>>n2;
		if(!n0&&!n1){for(int i=0;i<=n2;i++)cout<<1;continue;}
		if(!n2&&!n1){for(int i=0;i<=n0;i++)cout<<0;continue;}
		for(int i=0;i<=n0;i++)cout<<0;
		for(int i=0;i<=n2;i++)cout<<1;
		for(int i=0;i<n1-1;i++)cout<<(i&1);
	}
	return 0;
}