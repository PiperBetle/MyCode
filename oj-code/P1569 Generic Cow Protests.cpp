#include<iostream>
#include<cstdio>
#define max(a,b) (((a)>(b))?(a):(b))
#define int long long
using namespace std;
int a[10007];
int sum[10007];
int f[10007]={0};//前i头牛的最大理智 理智蒸发!!! 
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		if(sum[i]>=0)f[i]=1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++)
			if((f[j]>=1)&&(sum[i]-sum[j]>=0))f[i]=max(f[i],f[j]+1);
	if(f[n]>=1)cout<<f[n];
	else cout<<"Impossible";
		
	return 0;
}
