#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int f[1000007],g[1000007];
//f表示i列数量 g表示i列1砖数量 
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	//@Doncoi %%% Orz
	f[1]=1;g[1]=0;
	f[2]=2;g[2]=2;
	cin>>n;
	for(i=3;i<=n;i++)
	{
		f[i]=(f[i-1]+f[i-2]+g[i-1])%10000;
		g[i]=(f[i-2]*2+g[i-1])%10000;
	}
	cout<<f[n];
	
    return 0;
}
