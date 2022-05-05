#include<iostream>
using namespace std;
int main()
{
	int i,j;
	int n,m; 
	int a[21][21];
	int c1,c2;
	
	cin>>n>>m>>c1>>c2;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			if((i==0)||(j==0))
				a[i][j]=1;
	a[c1+1][c2+2]=a[c1+2][c2+1]=a[c1-1][c2-2]=a[c1-2][c2-1]=0;
	a[c1+1][c2-2]=a[c1+2][c2-1]=a[c1-1][c2+2]=a[c1-2][c2+1]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if((a[i][j]!=a[c1+1][c2+2])||(a[i][j]!=a[c1+2][c2+1])||(a[i][j]!=a[c1-1][c2-2])||(a[i][j]!=a[c1-2][c2-1])||
			(a[i][j]!=a[c1+1][c2-2])||(a[i][j]!=a[c1+2][c2-1])||(a[i][j]!=a[c1-1][c2+2])||(a[i][j]!=a[c1-2][c2+1]))
				a[i][j]=a[i-1][j]+a[i][j-1];
	cout<<a[n][m];
	
	return 0;
} 
