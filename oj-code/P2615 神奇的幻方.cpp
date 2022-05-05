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
int a[101][101];
int main()
{
	int i,j,n,t,x,y;
	
	cin>>n;
	x=1;
	y=n/2+1;
	t=n*n;
	for(i=1;i<=t;i++)
	{
		a[x][y]=i;
		x--;
		y++;
		if(x==0)x=n;
		if(y==(n+1))y=1;
		if(a[x][y]!=0)
		{
			x+=2;
			y--;
			if(x>n)x-=n;
			if(y==0)y=n;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
