#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	scanf("%lld",&n);
	for(i=1;i<=(n<<1)-6;i++)
		if(i&1)
		{
			for(j=1;j<=n-(i>>1);j++)
				putchar('o');
			for(j=1;j<=n-(i>>1);j++)
				putchar('*');
			printf("--");
			for(j=1;j<=(i>>1);j++)
				printf("o*");
			putchar('\n');
		}
		else
		{
			for(j=1;j<=n-(i>>1);j++)
				putchar('o');
			printf("--");
			for(j=1;j<=n-(i>>1);j++)
				putchar('*');
			for(j=1;j<=(i>>1);j++)
				printf("o*");
			putchar('\n');
		}
	printf("ooo*o**--*");
	for(i=1;i<=n-4;i++)
		printf("o*");
	putchar('\n');
	printf("o--*o**oo*");
	for(i=1;i<=n-4;i++)
		printf("o*");
	putchar('\n');
	printf("o*o*o*--o*");
	for(i=1;i<=n-4;i++)
		printf("o*");
	putchar('\n');
	printf("--o*o*o*o*");
	for(i=1;i<=n-4;i++)
		printf("o*");
	
    return 0;
}
