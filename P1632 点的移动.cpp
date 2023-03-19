#include<iostream>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;
struct point
{
	long long x,y;
}a[57];
long long ans[57],dis[57];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	long long i,j,k;
	long long n,m,t;
	
	for(i=0;i<57;i++)ans[i]=0x7fffffff;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
				dis[k]=abs(a[k].x-a[i].x)+abs(a[k].y-a[j].y);
			sort(dis+1,dis+1+n);
			int tot=0;
			for(k=1;k<=n;k++)
			{
				tot+=dis[k];
				ans[k]=min(ans[k],tot);
			}
		}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<"\n";
	
	return 0;
}
