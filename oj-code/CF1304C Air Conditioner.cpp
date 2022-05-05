#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define int long long
using namespace std;
struct customer
{
	int low,high,time;
};
customer a[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int left,right;
	
	cin>>T;
	a[0].time=0;
	while(T--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
			cin>>a[i].time>>a[i].low>>a[i].high;
		left=right=m;
		string ans="YES\n";
		for(i=1;i<=n;i++)
		{
			left-=a[i].time-a[i-1].time;
			right+=a[i].time-a[i-1].time;
			if(left>a[i].high||right<a[i].low)
			{
				ans="NO\n";
				break;
			}
			left=max(left,a[i].low);
			right=min(right,a[i].high);
		}
		cout<<ans;
	}
	
	return 0;
}
