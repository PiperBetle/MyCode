#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char b[51][51],a[101][101];
	int r,c,x,y,i,j;
	cin>>r>>c;
	
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
		{
			cin>>b[i][j];
			a[i][j]=b[i][j];
		}
			
	for(i=1;i<=r;i++)
		for(j=c+1;j<=2*c;j++)
			a[i][j]=b[i][2*c+1-j];
			
	for(i=r+1;i<=2*r;i++)
		for(j=1;j<=c;j++)
			a[i][j]=b[2*r+1-i][j];
			
	for(i=r+1;i<=2*r;i++)
		for(j=c+1;j<=2*c;j++)
			a[i][j]=b[2*r+1-i][2*c+1-j];
			
	cin>>x>>y;
	if (a[x][y]=='#') a[x][y]='.';
	else a[x][y]='#';
	for (i=1;i<=2*r;i++)
	{
		for(j=1;j<=2*c;j++) cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
