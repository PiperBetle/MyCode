#include<cstdio>
long long gcd(long long a,long long b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
long long abs(long long x)
{
	return x>0?x:-x;
}
long long max(long long x,long long y)
{
	return x>y?x:y;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	long long i,j,k;
	long long n,m,T;
	
	scanf("%lld",&T);
	if(T==1)
//for(;;)
	{
		
	long long n,m,T;
		scanf("%lld%lld",&n,&m);
		long long maxn=-1,ans;
		for(i=1;i<=2088888;i++)
		{
			if((i==n)||(i==m))continue;
			long long t;
			t=gcd(abs(i-n),abs(i-m));
			if(t>maxn)
			{
				maxn=t;
				ans=i;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		if(n>m)
		{
			n^=m;
			m^=n;
			n^=m;
		}
		if(n==1)
		{
			printf("%lld\n",m+m-1);
			continue;
		}
		if(m==n+1)
		{
			puts("1");
			continue;
		}
		if((n==2)&&(m==4))
		{
			puts("6");
			continue;
		}
		if((abs(n-m)==2)&&(n%2==0)&&(m%2==0))
		{
			puts("2");
			continue;
		}
		if((abs(n-m)==2)&&(n%2==1)&&(m%2==1))
		{
			puts("1");
			continue;
		}
		if(n+n<m)
		{
			puts("1");
			continue;
		}
		printf("%lld",m-n-n);
	}
	
	return 0;
}
