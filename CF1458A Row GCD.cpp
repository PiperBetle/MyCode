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
constexpr int N=2e5+1;
int n,m;
loli a[N],b[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	std::sort(a+1,a+1+n);
	if(n==1){for(int i=1;i<=m;i++)cout<<a[1]+b[i]<<' ';return 0;}
	auto g=a[2]-a[1];
	for(int i=3;i<=n;i++)g=std::__gcd(g,a[i]-a[i-1]);
	for(int i=1;i<=m;i++)cout<<std::__gcd(g,a[1]+b[i])<<' ';
	return 0;
}