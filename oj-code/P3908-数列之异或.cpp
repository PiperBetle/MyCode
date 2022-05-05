#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m=0,T;

	scanf("%lld",&n);
	if(n%4==0)
		printf("%lld\n",n);
	if(n%4==1)
		puts("1");
	if(n%4==2)
		printf("%lld\n",n+1);
	if(n%4==3)
		puts("0");
	
	return 0;
}