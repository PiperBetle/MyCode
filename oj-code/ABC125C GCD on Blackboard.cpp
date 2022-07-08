#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+2;
int n,ans,a[kN],pre[kN],suf[kN];
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)pre[i]=std::__gcd(pre[i-1],a[i]);
	for(int i=n;i>=1;i--)suf[i]=std::__gcd(suf[i+1],a[i]);
	for(int i=1;i<=n;i++)ans=std::max(ans,std::__gcd(pre[i-1],suf[i+1]));
	cout<<ans;
	return 0;
}