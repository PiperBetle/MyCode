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
	int n;cin>>n;
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		int t=n-mid%n;
		cout<<"+ "<<t<<endl;
		int e;cin>>e;
		if(e==(l+t)/n)r=mid;else l=mid;
		l+=t,r+=t;
	}
	cout<<"! "<<l;
	return 0;
}