#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,k,qw[21][3]={0},a[11][11]={0},x,y,ng[31],n,len;
	char nng[31];
	int ans[1001]={0,1},lans=1;;
	int sum=1;

	for(i=1;i<=9;i++)a[i][i]=1;
	scanf("%s%d",nng,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			i--;
			k--;
		}
		else
		{
			a[x][y]=1;
		}
	}
	y=21;
	while(y--)
	for(i=0;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			if((a[i][j]==1)&&(i!=j))
			{
				for(x=1;x<=9;x++)
				{
					if(a[j][x]==1)
					{
						a[i][x]=1;
					}
				}
			}
		}
	}
	y=n;
	len=strlen(nng);
	for(i=1;i<=len;i++)
	{
		ng[i]=nng[i-1]-'0';
	}
	for(i=1;i<=len;i++)
	{
		sum=0;
		for(j=0;j<=9;j++)
		{
			if(a[ng[i]][j]==1)sum++;
		}
		if(ng[i]==0)sum++;
		for(j=1;j<=lans;j++)
		{
			ans[j]*=sum;
		}
		for(j=1;j<=lans;j++)
		{
			ans[j+1]=ans[j+1]+ans[j]/10;
			ans[j]%=10;
		}
		if(a[lans+1]>=0)lans++;
	}
	for(i=1000;i>=1;i--)
	{
		if(ans[i]!=0)
		{
			for(;i>=1;i--)
			{
				cout<<ans[i];
			}
			break;
		}
	}

	return 0;
}
