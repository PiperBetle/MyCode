#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
auto MAX(auto x,auto y){return x>y?x:y;}
auto MIN(auto x,auto y){return x<y?x:y;}
int f[107],g[107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	f[0]=1;
	g[0]=0;
	for(i=1;i<=n;i++)
	{
		f[i]=3*g[i-1];
		g[i]=f[i-1]+2*g[i-1];
	}
	cout<<f[n];
	
    return 0;
}
