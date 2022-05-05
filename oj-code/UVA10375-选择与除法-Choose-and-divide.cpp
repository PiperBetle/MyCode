#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#define double long double
using namespace std;
double f[400007];
double c(int n,int m)
{
	return f[n]-f[m]-f[n-m];
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int a,b,x,y;
	
	for(i=1;i<400007;i++)
		f[i]=f[i-1]+log(i);
	while(~scanf("%lld%lld%lld%lld",&a,&b,&x,&y))
		printf("%.5Lf\n",exp(c(a,b)-c(x,y)));
	
	return 0;
}