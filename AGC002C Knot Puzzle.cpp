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
int n,m=1,k,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<n;i++)if(a[i]+a[i+1]>a[m]+a[m+1])m=i;
	if(a[m]+a[m+1]<k)return cout<<"Impossible",0;else cout<<"Possible\n";
	for(int i=1;i<m;i++)cout<<i<<'\n';
	for(int i=n-1;i>=m;i--)cout<<i<<'\n';
	return 0;
}