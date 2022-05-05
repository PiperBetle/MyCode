#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define MOD 19650827
using namespace std;
int a[2007],f[2007][2007][2];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i][0]=1;
	}
	for(k=1;k<=n;k++)
		for(i=1,j=i+k;j<=n;i++,j++)
		{
			if(a[i]<a[i+1])f[i][j][0]+=f[i+1][j][0];
			if(a[i]<a[j])f[i][j][0]+=f[i+1][j][1];
			if(a[j]>a[i])f[i][j][1]+=f[i][j-1][0];
			if(a[j]>a[j-1])f[i][j][1]+=f[i][j-1][1];
			f[i][j][0]%=MOD;
			f[i][j][1]%=MOD;
		}
	cout<<(f[1][n][0]+f[1][n][1])%19650827;
		
	return 0;
}
