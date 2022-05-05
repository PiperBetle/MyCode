#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct food
{
	int a,b,c;
};
food a[100007];
int f[100007];
bool cmp(food x,food y)
{
	return x.c*y.b<x.b*y.c;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int ans=-1;

	cin>>t>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].a;
	for(i=1;i<=n;i++)
		cin>>a[i].b;
	for(i=1;i<=n;i++)
		cin>>a[i].c;
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)
		for(j=t;j>=a[i].c;j--)
			f[j]=max(f[j],f[j-a[i].c]+a[i].a-j*a[i].b);
	for(i=1;i<=t;i++)
		ans=max(ans,f[i]);
	cout<<ans;
	
	return 0;
}