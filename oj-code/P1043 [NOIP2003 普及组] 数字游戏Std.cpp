#include<iostream>
using namespace std;
long long a[1001],x[1001],n,m,max1,min1=1000000000000000;
long long f[101][101][11],f1[101][101][11];
int main(){
	cin>>n>>m;
	for (int i=1;i<=100;i++)
		for (int j=1;j<=100;j++)
			for (int k=1;k<=10;k++)
				f1[i][j][k]=10000000000;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i];
		a[i]+=a[i-1]+x[i];
	}
	for (int i=n+1;i<=n*2;i++) a[i]+=a[i-1]+x[i-n];
	for (int i=1;i<=n*2;i++)
		for (int j=1;j<=n*2;j++)
		{
			f[i][j][1]=(a[j]-a[i-1]+100000000000)%10;
			f1[i][j][1]=(a[j]-a[i-1]+100000000000)%10;
		}
	for (int i=1;i<=n*2;i++)
	{
		for (int j=i+1;j<=n*2;j++) 
		{
			for (int l=2;l<=m;l++)
			{
				for (int k=i;k<j;k++)
				{
					f[i][j][l]=max(f[i][j][l],f[i][k][l-1]*f[k+1][j][1]);
					f1[i][j][l]=min(f1[i][j][l],f1[i][k][l-1]*f1[k+1][j][1]);
				}
			}
		}
	}
	for (int i=1;i<=n;i++) 
	{
		max1=max(max1,f[i][i+n-1][m]);
		min1=min(min1,f1[i][i+n-1][m]);
	}
	cout<<min1<<endl<<max1<<endl;
	
	return 0; 
}
