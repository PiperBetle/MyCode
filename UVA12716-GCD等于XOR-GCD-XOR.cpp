#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
inline int read()
{
	int f=1,w=0;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar()) w=(w<<1)+(w<<3)+(c^48);
	return w*f;
}
int f[30000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n=30000000,m,T=read();
	
	for(k=1;k<=(n>>1);k++)
		for(i=(k<<1);i<=n;i+=k)
		{
			j=i-k;
			if((i^j)==k)
				f[i]++;
		}
	for(i=1;i<=n;i++)
		f[i]+=f[i-1];
	for(i=1;i<=T;i++)
		printf("Case %lld: %lld\n",i,f[read()]);
	
	return 0;
}