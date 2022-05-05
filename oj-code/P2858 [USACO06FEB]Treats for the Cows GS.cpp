#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int f[2007][2007],a[2007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=a[i]*n;
	}
	for(i=2;i<=n;i++)
		for(j=1,k=j+i-1;j<=n,k<=n;j++,k++)
			f[j][k]=max(f[j][k-1]+a[k]*(n-i+1),f[j+1][k]+a[j]*(n-i+1));
	cout<<f[1][n];
	
	return 0;
}
