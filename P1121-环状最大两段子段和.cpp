#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	int _2=1,_3=1,_5=1,_7=1;
	a[1]=1;
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		m=min(min(a[_2]*2,a[_3]*3),min(a[_5]*5,a[_7]*7));
		if(m==a[_2]*2)_2++;
		else if(m==a[_3]*3)_3++;
		else if(m==a[_5]*5)_5++;
		else _7++;
		a[i]=m;
		if(a[i]==a[i-1])
			i--;
	}
	printf("%lld\n",a[n]);
	
	return 0;
}