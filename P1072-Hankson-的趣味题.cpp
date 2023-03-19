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
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T=read();
	int a0,a1,b0,b1;
	
	while(T--)
	{
		a0=read();a1=read();b0=read(),b1=read();
		a0=a0/a1;b0=b1/b0;
		k=0;
		for(i=1;i*i<=b1;i++)
			if(b1%i==0)
			{
				if(i%a1==0&&gcd(a0,i/a1)==1&&gcd(b0,b1/i)==1)
					k++;
				j=b1/i;
				if(i!=j&&j%a1==0&&gcd(a0,j/a1)==1&&gcd(b0,b1/j)==1)
					k++;
			}
		printf("%lld\n",k);
	}
	
    return 0;
}