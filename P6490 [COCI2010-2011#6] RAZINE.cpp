#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=n-1;i>=1;i--)
	{
		if(a[i]>=a[i+1])
		{
			ans+=(a[i]-a[i+1]+1);
			a[i]=a[i+1]-1;
		}
	}
	cout<<ans;
	
	return 0;
}

