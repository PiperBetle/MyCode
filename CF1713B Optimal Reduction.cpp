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
constexpr int N=1e5+1;
int T,n,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int p=int(std::max_element(a+1,a+1+n)-a);
		std::string ans="YES";
		for(int i=2;i<=p;i++)if(a[i-1]>a[i]){ans="NO";goto print;}
		for(int i=p;i<n;i++)if(a[i]<a[i+1]){ans="NO";goto print;}
		print:cout<<ans<<'\n';
	}
	return 0;
}