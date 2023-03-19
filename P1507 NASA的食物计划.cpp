#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int f[1007][1007],V[1007],M[1007],K[1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,v;
	
	cin>>v>>m>>n;
	for(i=1;i<=n;i++)
		cin>>V[i]>>M[i]>>K[i];
	for(i=1;i<=n;i++)
		for(j=v;j>=V[i];j--)
			for(k=m;k>=M[i];k--)
				f[j][k]=max(f[j][k],f[j-V[i]][k-M[i]]+K[i]);
	cout<<f[v][m];
	
	return 0;
}
