#include<cstdio>
#include<iostream>
using namespace std;
char a[1009][1009];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	int n,m,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='h')
			{
				if((i>3)&&(a[i-1][j]=='e')&&(a[i-2][j]=='h')&&(a[i-3][j]=='e'))ans++;
				if((j>3)&&(a[i][j-1]=='e')&&(a[i][j-2]=='h')&&(a[i][j-3]=='e'))ans++;
				if((a[i+1][j]=='e')&&(a[i+2][j]=='h')&&(a[i+3][j]=='e'))ans++;
				if((a[i][j+1]=='e')&&(a[i][j+2]=='h')&&(a[i][j+3]=='e'))ans++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
