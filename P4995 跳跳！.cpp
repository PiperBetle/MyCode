#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int a[2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	int left,right;
	
	cin>>n;
	left=1;right=n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(;;)
	{
		if(left>right)break;
		ans+=(a[right]-a[left-1])*(a[right]-a[left-1]);
		if(left==right)break;
		ans+=(a[right]-a[left])*(a[right]-a[left]);
		left++;
		right--;
	}
	cout<<ans;
	
    return 0;
}
