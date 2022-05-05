#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int f[107][20007];
int dfs(int n,int k)
{
	if(f[n][k]!=-1)
		return f[n][k];
	if(n==1)
		return f[n][k]=(k==0||k==1);
	return f[n][k]=(dfs(n-1,k)+dfs(n-1,k-1)*(4*n-2*k-2)+dfs(n-1,k-2)*(2*n-k-1)*(2*n-k))%504;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	for(i=0;i<107;i++)
		for(j=0;j<2007;j++)
			f[i][j]=-1;
	cin>>n>>k;
	if(k>=2*n)
	{
		cout<<"0";
		return 0;
	}
	cout<<dfs(n,k);
	
    return 0;
}
