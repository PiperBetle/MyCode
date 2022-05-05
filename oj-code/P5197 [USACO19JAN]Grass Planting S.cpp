#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[100007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y,ans=-1;
	
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x]++;
		a[y]++;
	}
	for(i=1;i<=n;i++)
		ans=max(ans,a[i]);
	cout<<ans+1;
	
	return 0;
}
