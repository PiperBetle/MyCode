#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	double a,b,c;
	double left=0,right=10000,mid;
	<=<=
	cin>>a>>b>>c;
	while(left+0.00001<right)
	{
		mid=(left+right)/2.00000;
		double rest=a;
		for(i=1;i<=c;i++)
			rest=rest-b+rest*(mid/100.00000);
		if(rest>0.00001)
			right=mid;
		else
			left=mid;
	}
	printf("%.1f",left);
	
    return 0;
}
