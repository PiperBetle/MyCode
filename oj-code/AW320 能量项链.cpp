#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int a[2007],f[2007][2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,n,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
	for(i=2;i<n*2;i++)for(j=i-1;j>=1&&i-j<n;j--)for(k=j;k<i;k++)
		ans=std::max(ans,f[j][i]=std::max(f[j][i],f[j][k]+f[k+1][i]+a[j]*a[k+1]*a[i+1]));
	cout<<ans;
	return 0;
}