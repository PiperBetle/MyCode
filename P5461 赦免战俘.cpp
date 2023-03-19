#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
int a[2001][2001]={0};
int pow2[11];
void qw(int m,int x,int y)
{
	int i,j,k;
	m/=2;
	for(i=x;i<=x+m-1;i++)
	{
		for(j=y;j<=y+m-1;j++)
		{
			a[i][j]=1;
		}
	}
	if(m==1)return;
	qw(m,x+m,y);
	qw(m,x+m,y+m); 
	qw(m,x,y+m);
}
int main()
{
	int n,m,i,j,k;
	
	pow2[0]=1;
	for(i=1;i<=10;i++)pow2[i]=pow2[i-1]<<1;
	scanf("%d",&n);
	qw(pow2[n],1,1);
	for(i=1;i<=pow2[n];i++)
	{
		for(j=1;j<=pow2[n];j++)
		{
			printf("%d ",1-a[i][j]);
		}
		puts("");
	}
	
    return 0;
}
