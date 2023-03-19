#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[107]={0},len=1;
signed main()
{
	// freopen("hexnum.in","r",stdin);
	// freopen("hexnum.out","w",stdout);
	int i,j,k;
	int n,m,t;

	scanf("%lld",&n);
	if(n==1)
	{
		puts("1");
		return 0;
	}
	for(k=0;;k++)
	{
		a[1]++;
		for(j=1;j<=len;j++)
			if(a[j]>1)
				a[j]=0,a[j+1]++;
			else
				break;
		if(a[len+1]>0)
			len++;
		m=0;
		for(j=len;j>=1;j--)
			m=m*10+a[j];
		if(m>n)
			break;
	}
	printf("%lld\n",k);
	
	return 0;
}