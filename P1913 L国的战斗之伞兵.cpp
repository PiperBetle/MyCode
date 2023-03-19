#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
char a[1007][1007];
int b[1007][1007]={0};
int n,m,ans=0;
void dfs(int x,int y)
{
	b[x][y]=1;
	if(a[x-1][y]=='d')
		dfs(x-1,y);
	if(a[x+1][y]=='u')
		dfs(x+1,y);
	if(a[x][y-1]=='r')
		dfs(x,y-1);
	if(a[x][y+1]=='l')
		dfs(x,y+1);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]=='o')
				dfs(i,j);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[i][j]==1)
				ans++;
	cout<<ans;
	
    return 0;
}
