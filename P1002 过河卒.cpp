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
int i,j,k,b,c,t,tt,n,m;
long long a[31][31];
int bx,by,cx,cy;
int main()
{
	for(i=0;i<=20;i++)
	{
		for(j=0;j<=20;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=1;i<=20;i++)
	{
		a[0][i]=1;
		a[i][0]=1;
	}
	cin>>bx>>by>>cx>>cy;
	a[cx][cy]=-1;
	a[cx+1][cy+2]=-1;
	if(cy>1)a[cx+1][cy-2]=-1;
	if(cx>0)a[cx-1][cy+2]=-1;
	if((cx>0)&&(cy>1))a[cx-1][cy-2]=-1;
	a[cx+2][cy+1]=-1;
	if(cy>0)a[cx+2][cy-1]=-1;
	if(cx>1)a[cx-2][cy+1]=-1;
	if((cx>1)&&(cy>0))a[cx-2][cy-1]=-1;
	for(i=1;i<=bx;i++)
	{
		for(j=1;j<=by;j++)
		{
			if(a[i][j]==0)
			{
				if((a[i-1][j]==-1)&&(a[i][j-1]==-1))
				{
					a[i][j]=0;
				}
				else
				{
					if((a[i-1][j]==-1)||(a[i][j-1]==-1))
					{
						a[i][j]=a[i-1][j]+a[i][j-1]+1;
					}
					else
					{
						a[i][j]=a[i-1][j]+a[i][j-1];
					}
				}
			}
		}
	}
	cout<<a[bx][by];

	return 0;
}
