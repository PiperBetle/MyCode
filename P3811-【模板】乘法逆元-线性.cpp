#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int inv[30000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int p,x,y;
	
	scanf("%lld%lld",&n,&p);
	inv[1]=1;
	for(i=2;i<=n;i++)
		inv[i]=(p-p/i)*inv[p%i]%p;
	for(i=1;i<=n;i++)
		printf("%lld\n",inv[i]);
	
	return 0;
}