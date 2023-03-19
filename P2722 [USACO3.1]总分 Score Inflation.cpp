#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int c[10007],w[10007],f[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>m>>n;
	for(i=1;i<=n;i++)
		cin>>w[i]>>c[i];
	for(i=1;i<=n;i++)
		for(j=c[i];j<=m;j++)
			f[j]=max(f[j],f[j-c[i]]+w[i]);
	cout<<f[m];
	
    return 0;
}
