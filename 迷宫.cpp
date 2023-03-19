#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
char a[101][101];
bool b[101][101];
int n,m,x1,y1,x2,y2;
int s(int x,int y)
{
	if((a[x1][y1]=='#')||(a[x2][y2]=='#'))
		return 0;
	if((x==x2)&&(y==y2))
		return 1;
	int i,j,k;
	for(i=-1;i<=1;i+=2)
	{
		x+=i;
		if((x>=0)&&(y>=0)&&(x<n)&&(y<n))
		{
			if(b[x][y]==0)
			{
				b[x][y]=1;
				if((x==x2)&&(y==y2))
					return 1;
//				if(a[x][y]=='.')
//					s(x,y);
				if((a[i][j]=='.')&&s(x,y))return 1;
				b[x][y]=0;
			}
		}
		x-=i;	
	}
	
	for(i=-1;i<=1;i+=2)
	{
		y+=i;
		if((x>=0)&&(y>=0)&&(x<n)&&(y<n))
		{
			if(b[x][y]==0)
			{
				b[x][y]=1;
				if((x==x2)&&(y==y2))
					return 1;
//				if(a[x][y]=='.')
//					s(x,y);
				if((a[i][j]=='.')&&s(x,y))return 1;
				b[x][y]=0;
			}
		}
		y-=i;
	}
	
	return 0;
}
int main()
{
	int i,j,k;
	
	cin>>m;
	while(m--)
	{
		cin>>n;
		getchar();
		for(i=0;i<=100;i++)
			for(j=0;j<=100;j++)
				b[i][j]=0;
		for(i=0;i<=100;i++)
			for(j=0;j<=100;j++)
				a[i][j]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cin>>a[i][j];
			getchar();
		}
		cin>>x1>>y1>>x2>>y2;
		if(s(x1,y1))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
