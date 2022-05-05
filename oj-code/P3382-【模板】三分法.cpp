#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define eps 1e-6
using namespace std;
double a[17];
int n;
double f(double x)
{
	double sum=0;
	for(int i=n;i>=0;i--)
		sum=sum*x+a[i];
	return sum;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int m,T;
	double left,right,mid;
	
	cin>>n>>left>>right;
	for(i=n;i>=0;i--)
		cin>>a[i];
	while(left+eps<right)
	{
		mid=(left+right)/2.000000;
		if(f(mid+eps)>f(mid-eps))left=mid;
		else right=mid;
	}
	printf("%.6f",left);
	
	return 0;
}