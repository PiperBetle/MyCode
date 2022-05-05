#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int f[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	
	f[1]=1;
	f[2]=2;
	for(i=3;i<=99999;i++)
		f[i]=f[i-1]+i-1;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(binary_search(f+1,f+100000,n))
			puts("1");
		else
			puts("0");
	}
	
    return 0;
}
