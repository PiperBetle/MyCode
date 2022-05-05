#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
bool pr[1000007];
int pt[1000007],len=0;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	for(i=0;i<1000000;i++)
		pr[i]=1;
	pr[1]=0;
	for(i=2;i<1000000;i++)
	{
		if(pr[i])
		{
			len++;
			pt[len]=i;
		}
		for(j=1;j<=len;j++)
		{
			if(i*pt[j]>=1000000)
				break;
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)
				break;
		} 
	}
	while(scanf("%lld",&n)!=EOF)
	{
		if(pr[n]==0)
		{
			printf("%lld is not prime.\n",n);
			continue;
		}
		for(t=n,m=0;;)
		{
			m=m*10+t%10;
			t/=10;
			if(t==0)
				break;
		}
		if(n!=m&&pr[m]==pr[n])
			printf("%lld is emirp.\n",n);
		else
			printf("%lld is prime.\n",n);
	}
	
    return 0;
}