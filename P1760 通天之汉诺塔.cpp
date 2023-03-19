#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
int a[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	a[0]=a[1]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=a[0];j++)
			a[j]<<=1;
		for(j=1;j<=a[0];j++)
		{
			a[j+1]+=a[j]/1000000;
			a[j]%=1000000;
		}
		if(a[a[0]+1]>0)
			a[0]++;
	}
	a[1]--;
	printf("%lld",a[a[0]]);
	for(i=a[0]-1;i>=1;i--)
		printf("%06lld",a[i]);
	
	return 0;
}
