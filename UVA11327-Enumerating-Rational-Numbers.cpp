#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
bool pr[300007];
int pt[300007],len=0;
int phi[300007];
inline int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int p,rest;
	
	for(i=0;i<300007;i++)
		pr[i]=1;
	pr[1]=0;
	phi[1]=1;
	for(i=2;i<300000;i++)
	{
		if(pr[i])
		{
			pt[++len]=i;
			phi[i]=i-1;
		}
		for(j=1;j<=len&&i*pt[j]<300000;j++)
		{
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)
			{
				phi[i*pt[j]]=phi[i]*pt[j];
				break;
			}
			phi[i*pt[j]]=phi[i]*(pt[j]-1);
		}
	}
	phi[1]++;
	for(i=2;i<=300000;i++)
		phi[i]+=phi[i-1];
	
	//线性筛
	while(scanf("%lld",&n))
	{
		if(n==0)
			return 0;
		if(n==1)
		{
			puts("0/1");
			continue;
		}
		if(n==2)
		{
			puts("1/1");
			continue;
		}
		p=lower_bound(phi+1,phi+300001,n)-phi;
		if(phi[p]==n)
		{
			printf("%lld/%lld\n",p-1,p);
			continue;
		}
		rest=n-phi[p-1];
		if(rest==1)
		{
			printf("1/%lld\n",p);
			continue;
		}
		for(i=2;rest!=1;i++)
		{
			rest-=(gcd(i,p)==1);
			if(rest==1)
				printf("%lld/%lld\n",i,p);
		}
	}
	
	return 0;
}