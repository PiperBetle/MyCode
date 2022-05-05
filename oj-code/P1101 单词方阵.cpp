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
char a[1001][1001]={0};
char str[11]="yizhong";
int go[11][11]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool b[1001][1001]={0};
int n;
bool s(int x,int y,int num,int ern)
{
	if((num==7)&&(a[x][y]=='g'))
	{
		b[x][y]=1;
		return 1;
	}
	x+=go[ern][0];
	y+=go[ern][1];
	if((x>=1)&&(y>=1)&&(x<=n)&&(y<=n)&&(a[x][y]==str[num]))
	{
		if(s(x,y,num+1,ern))
		{
			b[x-go[ern][0]][y-go[ern][1]]=1;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int m,i,j,k,x,y;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]=='y')
			{
				for(k=0;k<=7;k++)
				{
					if(s(i,j,1,k)==1)
					{
						b[i][j]=1;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(b[i][j]==0)
			{
				cout<<"*";
			}
			else
			{
				cout<<a[i][j];
			}
		}
		cout<<endl;
	}
	
	return 0;
}
