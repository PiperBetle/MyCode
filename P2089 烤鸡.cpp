#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans[100001][11],lans=0,a[11],n;
void qw(int now,int sum)
{
	int i;
	if(now==11)
	{
		if(sum==0)
		{
			lans++;
			for(i=1;i<=10;i++)ans[lans][i]=a[i]+1;
		}
		return;
	}
	for(i=0;i<=2;i++)
	{
		if(sum>=i)
		{
			a[now]=i;
			qw(now+1,sum-i);
		}
	}
}
int main()
{
	int i,j;
	
	scanf("%d",&n);
	n-=10;
	if(n<0)cout<<0;
	else
	{
		qw(1,n);
		cout<<lans<<endl;
		for(i=1;i<=lans;i++)
		{
			for(j=1;j<=10;j++)
			{
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
