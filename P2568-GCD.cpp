#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int pt[10000007],len,phi[10000007];
bool pr[10000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	
	scanf("%lld",&n);
	phi[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!pr[i])
			pt[++len]=i,phi[i]=i-1;
		for(j=1;j<=len&&i*pt[j]<=n;j++)
		{
			pr[i*pt[j]]=1;
			if(!(i%pt[j]))
			{
				phi[i*pt[j]]=phi[i]*pt[j];
				break;
			}
			phi[i*pt[j]]=phi[i]*(pt[j]-1);
		}
	}
	for(i=1;i<=n;i++)
		phi[i]+=phi[i-1];
	for(i=1;i<=len;i++)
		ans+=(phi[n/pt[i]]<<1);
	printf("%lld\n",ans-len);
	
	return 0;
}