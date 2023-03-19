#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+2;
int n;
pii a[kN];
loli ans[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
	std::sort(a+1,a+1+n,std::greater<>());
	for(int i=1,j=kN;i<=n;i++)if(a[i].first!=a[i+1].first)
		ans[j=std::min(j,a[i].second)]+=1ll*i*(a[i].first-a[i+1].first);
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}