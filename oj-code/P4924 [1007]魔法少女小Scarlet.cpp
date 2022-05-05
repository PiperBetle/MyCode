#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define int long long
using namespace std;
int a[1007][1007],b[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int x,y,r,z;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=(i-1)*n+j;
//	cout<<"Good!\n";
	while(m--)
	{
		cin>>x>>y>>r>>z;
		if(z==0)
		{
			for(i=x-r;i<=x+r;i++)
				for(j=y-r;j<=y+r;j++)
					b[x-y+j][x+y-i]=a[i][j];
			for(i=x-r;i<=x+r;i++)
				for(j=y-r;j<=y+r;j++)
					a[i][j]=b[i][j];
		}
		else
		{ 
			 for(i=x-r;i<=x+r;i++)
				for(j=y-r;j<=y+r;j++)
					b[x+y-j][y-x+i]=a[i][j];
			 for(i=x-r;i<=x+r;i++)
				for(j=y-r;j<=y+r;j++)
					a[i][j]=b[i][j];
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cout<<a[i][j]<<(j==n?"\n":" ");
	
    return 0;
}
