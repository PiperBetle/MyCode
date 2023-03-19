#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);

	long double a[10086],b,n,t,sum=0;
	int i,j,k;	
	
	cin>>n>>a[0]>>b;
	for(i=1;i<=n;i++)
	{
		a[i]=sqrt(b*b+a[i-1]*a[i-1]);
		sum=sum+b*a[i-1]/2;
	}
	printf("%0.6Lf",sum);
	
	return 0;
}
