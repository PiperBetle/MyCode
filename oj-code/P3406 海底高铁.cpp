#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	int x,y,z;
	
	cin>>n>>m;
	cin>>x;
	for(i=2;i<=m;i++)
	{
		cin>>y;
		a[min(x,y)]++;
		a[max(x,y)]--;
		x=y;
	}
	for(i=1;i<n;i++)
	{
		a[i]+=a[i-1];
		cin>>x>>y>>z;
		ans+=min(a[i]*x,a[i]*y+z);
	}
	cout<<ans;
	
    return 0;
}
