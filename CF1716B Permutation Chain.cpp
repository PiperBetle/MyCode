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
constexpr int N=102;
int T,n,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>T;while(T--){
		cin>>n;cout<<n<<'\n';
		for(int i=1;i<=n;i++)a[i]=i;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cout<<a[j]<<' ';
			cout<<'\n';
			std::swap(a[i],a[i+1]);
		}
	}
	return 0;
}