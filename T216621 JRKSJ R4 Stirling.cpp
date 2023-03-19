#include<iostream>
#include<cstdio>
#define int long long
signed main()
{
	int n,ans=1;
	scanf("%lld",&n);
	for(;n>=3;n--)ans=ans*n%998244353;
	printf("%lld",ans);
	return 0;
}