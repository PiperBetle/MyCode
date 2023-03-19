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
constexpr int N=1001;
int n,x[N],y[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
		if(n%2){cout<<"1\n";continue;}
		std::sort(x+1,x+1+n);std::sort(y+1,y+1+n);
		cout<<1ll*(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1)<<'\n';
	}
	return 0;
}