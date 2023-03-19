#include<cstdio>
#include<iostream>
#define int long long
#define max(a,b) ((a)>(b)? a:b)
using namespace std;
int pr[1000007],len;
bool pt[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int ans,p;

	for(i=2;i<=1000000;i++)
	{
		if(!pt[i])
			pr[++len]=i;
		for(j=1;i*pr[j]<=1000000&&j<=len;j++)
		{
			pt[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}

	for(k=1;;k++)
	{
		int c=2;
		scanf("%lld",&n);
		m=n;
		if(n==0)
			return 0;
		printf("Case %lld: ",k);
		ans=p=0;
		for(j=1;pr[j]*pr[j]<=n;j++)
		{
			i=pr[j];
			t=n;
			p=1;
			while(n%i==0)
			{
				n/=i;
				p*=i;
			}
			if(p!=1)
				ans+=p,c--;
		}
		if(n>1)
			c--,ans+=n;
		printf("%lld\n",ans+max(0,c));
	}
	
	return 0;
}