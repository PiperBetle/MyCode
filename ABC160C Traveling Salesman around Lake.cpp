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
constexpr int kN=2e5+1;
int n,m,a[kN];
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=m+a[1]-a[n];
	for(int i=1;i<n;i++)ans=std::max(ans,a[i+1]-a[i]);
	cout<<m-ans;
	return 0;
}