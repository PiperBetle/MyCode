#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1007],sum[1007],f[1007][1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k,p,q;
	int n,m,ans;
	 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(i=1;i<=n*2;i++)
		sum[i]=sum[i-1]+a[i];
	
//	memset(f,0x3f,sizeof f);
	for(i=1;i<=n;i++)f[i][i]=0;
	for(p=1;p<n;p++)
		for(i=1,j=i+p;(i<n*2)&&(j<n*2);i++,j=i+p){f[i][j]=1e9;
			for(k=i;k<j;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);}
	ans=1e9;
	for(i=1;i<=n;i++)ans=min(ans,f[i][i+n-1]);
	cout<<ans<<endl;
	
	memset(f,0,sizeof f);
	for(i=1;i<=n;i++)f[i][i]=0;
	for(p=1;p<n;p++)
		for(i=1,j=i+p;(i<n*2)&&(j<n*2);i++,j=i+p)
			for(k=i;k<j;k++)
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
	ans=-1e9;
	for(i=1;i<=n;i++)ans=max(ans,f[i][i+n-1]);
	cout<<ans;
	
	return 0;
}
