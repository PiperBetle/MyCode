#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
constexpr int kN=5e4+7,inf=0x3f3f3f3f;
int sum[kN],f[kN],h[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;h[0]=-inf;
	for(int i=1;i<=n;i++)cin>>sum[i],sum[i]+=sum[i-1];
	std::fill_n(f+1,n,inf);
	for(int i=1;i<=n;i++)for(int j=0;j<i;j++){
		if(sum[i]-sum[j]<h[j])continue;
		f[i]=std::min(f[i],f[j]+i-j-1);
		h[i]=sum[i]-sum[j];
	}
	cout<<f[n];
	return 0;
}