#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
#define eps 1e-4
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
double a[100007];
int n,k;
bool check(double x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=(int)(a[i]/x);
	return cnt>=k;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j;
	int m,T;
	
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	double left=0.0000,right=100000.0000,mid;
	while(left+eps<right)
	{
		mid=(left+right)/2.0000;
		if(check(mid))left=mid;
		else right=mid;
	}
	printf("%.2Lf\n",left-0.005+eps);
	
	return 0;
}