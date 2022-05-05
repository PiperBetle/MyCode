#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int f[1007][1007][2];
int a[1007],p[1007],sum[1007];//Î»ÖÃ ¹¦ÂÊ 
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,c;
	
	cin>>n>>c;
	memset(f,0x3f,sizeof(f));
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>p[i];
		sum[i]=sum[i-1]+p[i];
	}
	f[c][c][0]=f[c][c][1]=0;
	for(k=2;k<=n;k++)
		for(i=1,j=i+k-1;j<=n;i++,j++)
		{
			f[i][j][0]=min(f[i+1][j][0]+(a[i+1]-a[i])*(sum[i]+sum[n]-sum[j]),
               f[i+1][j][1]+(a[j]-a[i])*(sum[i]+sum[n]-sum[j]));
            f[i][j][1]=min(f[i][j-1][0]+(a[j]-a[i])*(sum[i-1]+sum[n]-sum[j-1]),
               f[i][j-1][1]+(a[j]-a[j-1])*(sum[i-1]+sum[n]-sum[j-1]));
		}
	cout<<min(f[1][n][0],f[1][n][1]);
	
	return 0;
}
