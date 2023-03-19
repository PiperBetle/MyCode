#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[3000007],q[3000007],sum[3000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int ans=0,left,right;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(i=n+1;i<=(n<<1)-1;i++)
		sum[i]=sum[i-1]+a[i];
	left=right=q[1]=1;
	for(i=1;i<=(n<<1)-1;i++)
	{
		while(left<=right&&max(i-n+1,1)>q[left])
			left++;
		while(left<=right&&sum[q[right]]>=sum[i])
			right--;
		q[++right]=i;
		if(i>=n&&sum[q[left]]>=sum[i-n])
			ans++;
	}
	cout<<ans<<'\n';
	
	return 0;
}