#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
char a[11][11],b[11][11];
int abs(int _x)
{
	if(_x>0)return _x;
	return -_x;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int x,y;
	int n,m,ans=0;
	
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
		{
			cin>>a[i][j];
			b[i][j]='A'+(i-1)*4+j-1;
		}
//	b[4][4]='.';
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			for(x=1;x<=4;x++)
				for(y=1;y<=4;y++)
					if(a[i][j]==b[x][y])
						ans+=(abs(i-x)+abs(j-y));
	cout<<ans;
	
	return 0;
}
