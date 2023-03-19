#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int a[2007],b[2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans;
	int left_a,right_a,left_b,right_b;
	
	while(cin>>n)
	{
		if(n==0)return 0;
		ans=0;
		left_a=left_b=1;
		right_a=right_b=n;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(i=1;i<=n;i++)
		{
			if(a[left_a]>b[left_b])
			{
				left_a++;
				left_b++;
				ans+=200;
				continue;
			}
			if(a[left_a]<b[left_b])
			{
				left_a++;
				right_b--;
				ans-=200;
				continue;
			}
			if(a[right_a]>b[right_b])
			{
				right_a--;
				right_b--;
				ans+=200;
				continue;
			}
			else
			{
				if(a[left_a]!=b[right_b])
					ans-=200;
				left_a++;
				right_b--;
				continue;
			}
		}
		cout<<ans<<'\n';
	}
	
    return 0;
}
