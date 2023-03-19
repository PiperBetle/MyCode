#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
bool pr[10000007];
int pt[10000007],len;
bool b[1000007];
inline int read()
{
	int f=1,w=0;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar()) w=(w<<1)+(w<<3)+(c^48);
	return w*f;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T=read();
	int rest;
	
	for(i=0;i<10000000;i++)
		pr[i]=1;
	pr[1]=0;
	for(i=2;i<10000000;i++)
	{
		if(pr[i])
			pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<10000000;j++)
		{
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)
				break;
		}
	}

	while(T--)
	{
		n=read();
		memset(b,0,sizeof b);
		while(n--)
		{
			rest=read();
			for(i=1;pt[i]*pt[i]<=rest;i++)
				while(rest%pt[i]==0)
				{
					b[pt[i]]=1;
					rest/=pt[i];
				}
			if(rest>1)
				b[rest]=1;
		}
		for(i=1;;i++)
			if(b[pt[i]]==0)
			{
				printf("%lld\n",pt[i]);
				break;
			}
	}
	
	return 0;
}