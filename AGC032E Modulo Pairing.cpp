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
constexpr int kN=2e5+1;
int n,m,a[kN];
bool check(int x){
	for(int i=x+1,j=n;i<=j;i++,j--)if(a[i]+a[j]<m)return false;
	return true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;n*=2;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	int l=0,r=n/2,mid,ans=-1,sum=0;
	for(;l<=r;)if(check(2*(mid=(l+r)/2)))ans=mid*2,r=mid-1;else l=mid+1;
	for(int i=1,j=ans;i<=j;i++,j--)sum=std::max(sum,a[i]+a[j]);
	for(int i=ans+1,j=n;i<=j;i++,j--)sum=std::max(sum,a[i]+a[j]-m);
	cout<<sum;
	return 0;
}