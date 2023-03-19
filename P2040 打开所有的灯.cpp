#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[5][5],b[5][5];
int re(int x,int y)
{
	a[x-1][y-1]=!a[x-1][y-1];
	a[x-1][y]=!a[x-1][y]
	a[x-1][y+1]=!a[x-1][y+1]
	a[x][y-1]=!
	a[x][y+1]=!
	a[x+1][y-1]=!
	a[x+1][y]=!
	a[x+1][y+1]=!
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	for(i=1;i<=3;i++)for(j=1;j<=3;j++)cin>>a[i][j];
	
	return 0;
}
