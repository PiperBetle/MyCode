#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int n,k,a[807][807],sum[807][807];
bool check(int x){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(a[i][j]>=x);
	for(int i=k;i<=n;i++)for(int j=k;j<=n;j++)
		if(sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]<(k*k/2)+1)return 0;
	return 1;
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	int l=1,r=1e9,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}