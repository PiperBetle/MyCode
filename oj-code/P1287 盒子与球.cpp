#include<iostream>
#include<cstdio>
#define MOD 100
using namespace std;
int main()
{
	int a[11][11]={0},n,r;
	int i,j,k;

	scanf("%d%d",&n,&r);
	a[0][0]=1;
	for(i=1;i<=n;i++)
    {
        for(j=1;j<=r;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j]*j;
        }
    }
    for(i=1;i<=r;i++)
    {
    	a[n][r]*=i;
	}
	printf("%d",a[n][r]);
	
	return 0;
}
