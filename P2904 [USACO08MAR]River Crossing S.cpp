#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int sum[10007],a[10007],f[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	memset(f,0x3f,sizeof f);
	cin>>n>>m;
	sum[0]=m<<1;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	f[0]=0;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			f[j]=min(f[j],f[j-i]+sum[i]);
	cout<<f[n]-m;
	
    return 0;
}
