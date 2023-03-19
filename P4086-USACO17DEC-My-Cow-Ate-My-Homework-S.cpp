#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define double long double
using namespace std;
auto abs(auto x){return x>0?x:-x;}
double a[1000007];
double sum[1000007];//后缀和
double minn[1000007];//后缀最小值 
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	double ans=-1;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	minn[n]=sum[n]=a[n];
	for(i=n-1;i>=1;i--)
	{
		sum[i]=sum[i+1]+a[i];
		minn[i]=min(minn[i+1],a[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		double b=sum[i]/(n-i+1);
		if(b-ans>0.0000001)
			ans=b;
	}
	for(i=1;i<=n-1;i++)
	{
		double b=sum[i]/(n-i+1);
		if(abs(b-ans)<0.0000001)
			cout<<i-1<<"\n";
	}
	
    return 0;
}
