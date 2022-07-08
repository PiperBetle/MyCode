#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+7;
int a[kN];
signed main(){
//	freopen("dice.in","r",stdin);
//	freopen("dice.out","w",stdout);
	int n,k;cin>>n>>k;
	double ans=0,sum=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++)ans=std::max(ans,sum+=(1+a[i])/2.);
	for(int i=k+1;i<=n;i++)ans=std::max(ans,(sum+=(1+a[i])/2.)-=(1+a[i-k])/2.);
	printf("%.10f",ans);
	return 0;
}