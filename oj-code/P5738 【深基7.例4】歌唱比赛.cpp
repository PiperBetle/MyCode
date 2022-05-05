#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int a[101][101]={0};
	int n,m,i,j,k,t,maxn=-1,ii,jj;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
		for(ii=1;ii<=m;ii++)
		{
			for(jj=1;jj<=m-ii;jj++)
			{
				if(a[i][jj]>a[i][jj+1])
				{
					swap(a[i][jj],a[i][jj+1]);
				}
			}
		}
		for(j=2;j<=m-1;j++)a[i][0]+=a[i][j];
		if(a[i][0]>maxn)maxn=a[i][0];
	}
	printf("%.2f",(double)((double)(maxn)/(double)(m-2)));
	
	return 0;
}
