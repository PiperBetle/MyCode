#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[100007],sum[100007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	while(cin>>n)
	{
		m=(n*(n-1))>>1;
		for(i=1;i<=m;i++)
			cin>>sum[i];
		sort(sum+1,sum+1+m);
		for(i=1;i<=100000;i++)//& 枚举sum1
		{
			a[1]=i;
			for(j=2;j<=n;j++)//& 计算aj
			{
				a[j]=sum[j*(j+1)/2+1]-a[1];
				for(k=2;k<=j-1;k++)
					if(a[k]+a)
			}
		}
	}
	
	return 0;
}
// 0+1 1+1 3+1 6+1 10+1
//  j*(j-1)/2+1
// 0 