#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
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
constexpr int N=1e5+2;
int n,m,sum,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;m=n*(n+1)/2;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	if(sum%m)return cout<<"NO",0;else m=sum/m;
	a[n+1]=a[1];
	for(int i=1;i<=n;i++)a[i]=a[i]-a[i+1]+m;
	for(int i=1;i<=n;i++)if(a[i]<0||a[i]%n)return cout<<"NO",0;else m-=a[i]/n;
	cout<<(m?"NO":"YES");
	return 0;
}