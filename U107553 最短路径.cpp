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
int sx,sy,ex,ey,ans=0,minn=999999,n;
char a[30][30],b[30][30];
void s(int x,int y,int foot)
{
	int i,j;
	for(i=-1;i<=1;i+=2)
	{
		for(j=-1;j<=1;j+=2)
		{
			x+=i;
			y+=j;
			if((1<=x)&&(x<=n)&&(1<=y)&&(y<=n))
			{
				if((a[i][j]==0)&&(i!=sx)&&(j!=sy))
				{
					b[i][j]=1;
					foot++;
					if((x==ex)&&(y==ey))
					{
						if(foot<minn)minn=foot;
					}
					else
					{
						s(x,y,foot);
					}
					foot--;
					b[i][j]=0;
				}
			}
			x-=i;
			y-=j;
		}
	}
}
void ss(int x,int y,int foot)
{
	int i,j;
	for(i=-1;i<=1;i+=2)
	{
		for(j=-1;j<=1;j+=2)
		{
			x+=i;
			y+=j;
			if((1<=x)&&(x<=n)&&(1<=y)&&(y<=n))
			{
				if((a[i][j]==0)||((i!=sx)&&(j!=sy)))
				{
					b[i][j]=1;
					foot++;
					if((x==ex)&&(y==ey))
					{
						if(foot==minn)ans++;
					}
					else
					{
						s(x,y,foot);
					}
					foot--;
					b[i][j]=0;
				}
			}
			x-=i;
			y-=j;
		}
	}
}
int main()
{
	int i,j,k;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			b[i][j]=0;
			if(a[i][j]=='X')
			{
				b[i][j]=1;
			}
			else
			{
				if(a[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				else
				{
					if(a[i][j]=='E')
					{
						ex=i;
						ey=j;
					}
				}
			}
		}
	}
	s(sx,sy,0);
	ss(sx,sy,0);
	cout<<minn<<endl<<ans;
	
	return 0;
}
