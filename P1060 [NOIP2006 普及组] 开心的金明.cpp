#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int c[1007],w[1007],f[10000007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>c[i]>>w[i];
		w[i]*=c[i];
	}
	for(i=1;i<=n;i++)
		for(j=m;j>=c[i];j--)
			f[j]=max(f[j],f[j-c[i]]+w[i]);
	cout<<f[m];
	
	return 0;
}
