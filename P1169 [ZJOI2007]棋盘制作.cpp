#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct point
{
	int data,left,right,up;
};
point a[2007][2007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int ans1=1,ans2=1;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j].data;
			a[i][j].left=a[i][j].right=j;
			a[i][j].up=1;
		}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<m;j++)
			if(a[i][j].data!=a[i][j+1].data)
				a[i][j+1].left=a[i][j].left;
		for(j=m;j>1;j--)
			if(a[i][j].data!=a[i][j-1].data)
				a[i][j-1].right=a[i][j].right;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(i>1&&a[i][j].data!=a[i-1][j].data)
			{
				a[i][j].up=a[i-1][j].up+1;
				a[i][j].left=max(a[i][j].left,a[i-1][j].left);
				a[i][j].right=min(a[i][j].right,a[i-1][j].right);
				int x=a[i][j].right-a[i][j].left+1;
				int y=min(x,a[i][j].up);
				ans1=max(ans1,y*y);
				ans2=max(ans2,x*a[i][j].up);
			}
		}
	cout<<ans1<<'\n'<<ans2<<'\n';
	
	return 0;
}