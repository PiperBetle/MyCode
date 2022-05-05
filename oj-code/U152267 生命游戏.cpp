#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[1007][1007];
int a[1007][1007];
inline int sum(int i,int j)
{
	return c[i-1][j-1]-'0'+c[i-1][j]-'0'+c[i-1][j+1]-'0'+
	       c[i][j-1]  -'0'+              c[i][j+1]  -'0'+
	       c[i+1][j-1]-'0'+c[i+1][j]-'0'+c[i+1][j+1]-'0';
}
int main()
{
//	freopen("life.in","r",stdin);
//	freopen("life.out","w",stdout);
	int i,j,k;
	int t,T,_n,n,m;
	int _i,_j,_k;
	
	for(i=0;i<1007;i++)for(j=0;j<1007;j++)a[i][j]=0,c[i][j]='0';
	cin>>m>>n>>t;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	{
		cin>>c[i][j];
		a[i][j]=c[i][j]-'0';
	}
	t--;
	while(t--)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(c[i][j]=='1')
				{
					if((sum(i,j)>3)||(sum(i,j)<2))
					{
						a[i][j]=-1;
					}
				}
				else
				{
					if(sum(i,j)==3)
					{
						a[i][j]=2;
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]==-1)
				{
					a[i][j]=0;
					c[i][j]='0';
				}
				if(a[i][j]==2)
				{
					a[i][j]=1;
					c[i][j]='1';
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)cout<<c[i][j];
		cout<<endl;
	}
	
	return 0;
}
