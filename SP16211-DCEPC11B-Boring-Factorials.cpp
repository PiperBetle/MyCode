#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int qp(int n,int p,int k,int t=1)
{
	if(!p)
		return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)
			t=t*n%k;
	return t;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int p;
	
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&n,&p);
		if(p<=n)
		{
			puts("0");
			continue;
		}
		m=1;
		for(i=n+1;i<p;i++)
			m=m*i%p;
		printf("%lld\n",(p-1)*qp(m,p-2,p)%p);
	}
	
	return 0;
}