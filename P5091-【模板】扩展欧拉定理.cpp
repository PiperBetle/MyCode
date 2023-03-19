#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int phi(int n)
{
	int ans=n;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
		{
			ans-=ans/i;
			while(n%i==0)
				n/=i;
		}
	if(n>1)
		ans-=ans/n;
	return ans;
}
int qp(int n,int p,int k,int t=1)
{
	if(p==0)return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1) t=t*n%k;
	return t;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int a,b=0,flag=0;
	char c;
	
	scanf("%lld%lld",&a,&m);
	int M=phi(m);
	for(;isdigit(c);c=getchar())
	{
		b=(b<<1)+(b<<3)+(c^48);
		if(b>=M)
			flag=1;
		b%=M;
	}
	if(flag)
		b+=M;
	printf("%lld\n",qp(a,b,m));
	return 0;
}