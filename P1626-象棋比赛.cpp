#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[100007],b[100007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int ans=0;
	
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	for(;k>=1;k--)
		ans+=b[k];
	cout<<ans<<'\n';
	
	return 0;
}