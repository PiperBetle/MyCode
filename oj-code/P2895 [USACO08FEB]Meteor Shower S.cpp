#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int n,m,ans,x,y,t;
int dx[4]={0,0,-1,1},
	dy[4]={1,-1,0,0};
int m[1007][1007],b[1007][1007],a[1007][1007];
queue<int> q[2];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	
	cin>>n;
	for(i=0;i<1007;i++)
		for(j=0;j<1007;j++)
			m[i][j]=-1;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>t;
	}
	
    return 0;
}
