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
int n,a[N],f[N][2];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],f[a[i]][i&1]++;
		std::sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)f[a[i]][i&1]--;
		cout<<[]{for(int i=1;i<=n;i++)if(f[a[i]][0]||f[a[i]][1])return "NO\n";return "YES\n";}();
		for(int i=1;i<=n;i++)f[a[i]][0]=f[a[i]][1]=0;
	}
	return 0;
}