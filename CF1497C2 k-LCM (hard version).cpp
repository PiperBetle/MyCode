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
	int T;cin>>T;for(int n,k;T--;){
		cin>>n>>k;
		n-=k-3;
		for(int i=k-3;i;i--)cout<<"1 ";
		if(n&1)cout<<1<<' '<<n/2<<' '<<n/2<<'\n';
		else if(n%4==0)cout<<n/2<<' '<<n/4<<' '<<n/4<<'\n';
		else cout<<2<<' '<<n/2-1<<' '<<n/2-1<<'\n';
	}
	return 0;
}