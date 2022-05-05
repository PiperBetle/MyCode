#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int f[1007][1007],h[1007],t[1007],z[1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,v,g;
	int ans=-1;
	
	cin>>v>>g>>n;
	for(i=1;i<=n;i++)
		cin>>h[i]>>t[i]>>z[i];
	for(k=1;k<=n;k++)
		for(i=v;i>=t[k];i--)
			for(j=g;j>=z[k];j--)
				f[i][j]=max(f[i-t[k]][j-z[k]]+h[k],f[i][j]);
	cout<<f[v][g];
	
	return 0;
}
