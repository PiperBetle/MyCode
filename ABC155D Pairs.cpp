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
int n,a[kN];
loli m;
bool check(loli x){
	loli cnt=0;
	for(int i=0;i<n;i++)
		if(a[i]<0){
			int l=i,r=n;
			for(int mid;l+1<r;)if(1ll*a[i]*a[mid=(l+r)/2]<=x)r=mid;else l=mid;
			cnt+=n-r;
		}else{
			int l=i,r=n;
			for(int mid;l+1<r;)if(1ll*a[i]*a[mid=(l+r)/2]<=x)l=mid;else r=mid;
			cnt+=l-i;
		}
	return cnt<m;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;for(int i=0;i<n;i++)cin>>a[i];
	std::sort(a,a+n);
	loli l=-1e18,r=1e18;
	for(loli mid;l+1<r;)if(check(mid=(l+r)/2))l=mid;else r=mid;
	cout<<r;
	return 0;
}