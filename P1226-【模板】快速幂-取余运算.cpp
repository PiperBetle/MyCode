#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int qp(int n,int p,int k)
{
	if(p==0)return 1;
	int t=qp(n,p/2,k)%k;
	t=(t*t)%k;
	if(p%2==1)t=(t*n)%k;
	return t;
}
// inline int qp(int a,int p,int k,int t=1){for(;p;a=a*a,p>>=1)if(p&1)t=t*a;return t;}
signed main()
{
//	freopen("mod.in","r",stdin);
//	freopen("mod.out","w",stdout);
	int i,j,k;
	int n,m,t;
	int p;
	
	scanf("%lld%lld%lld",&n,&p,&k);
	printf("%lld^%lld mod %lld=",n,p,k);
	n%=k;
	printf("%lld\n",qp(n,p,k)%k);
		
	return 0;
}