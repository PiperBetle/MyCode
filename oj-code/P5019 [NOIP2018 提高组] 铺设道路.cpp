#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1000007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	int ans=a[1];
	for(i=1;i<n;i++)
		if(a[i+1]>a[i])ans=ans+a[i+1]-a[i];
	cout<<ans;
	
	return 0;
}
