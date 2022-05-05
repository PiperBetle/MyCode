#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	char a[201][201]={0};
	int num[201][201]={0},i,j,m,n;
	
	scanf("%d%d",&n,&m);
//	getchar();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='*')
			{
				num[i-1][j-1]++;
				num[i-1][j]++;
				num[i-1][j+1]++;
				num[i][j-1]++;
				num[i][j+1]++;
				num[i+1][j-1]++;
				num[i+1][j]++;
				num[i+1][j+1]++;
			}
		}
		getchar();
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='?')
			{
				printf("%d",num[i][j]);
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	
	return 0;
}
