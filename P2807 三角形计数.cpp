#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int T;
	long long n;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n&1)printf("%lld\n",(n+1)*(2*n*n+3*n-1)/8);
		else printf("%lld\n",n*(n+2)*(2*n+1)/8);
	}
	
	return 0;
}
