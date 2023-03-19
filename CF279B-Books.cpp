#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using namespace std;
int a[100007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	int left=1,right=1;

	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(;;)
	{
		while(right<=n&&m>=a[right])
			m-=a[right++];
		ans=max(right-left,ans);
		if(right==n+1)
			break;
		m+=a[left++];
	}
	cout<<ans<<'\n';
	
	return 0;
}