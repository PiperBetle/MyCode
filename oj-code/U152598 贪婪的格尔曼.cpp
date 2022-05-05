#include<iostream>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long n,s,b;
long long S[1005],B[1005],c[1005];
long long dp[55][55];
signed main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	cin>>n>>s>>b;
	memset(dp,127,sizeof(dp));
	for(i=1;i<=n;++i)cin>>S[i]>>B[i]>>c[i];
	dp[0][0]=0;
	for(i=1;i<=n;++i)
	{
		for(j=s;j>=0;--j)
		{
			for(k=b;k>=0;--k)
			{
				int x=min(s,j+S[i]);
				int y=min(b,k+B[i]);
				dp[x][y]=min(dp[x][y],dp[j][k]+c[i]); 
			}
		}
	}
	cout<<dp[s][b]*2;
	
	return 0;
}
