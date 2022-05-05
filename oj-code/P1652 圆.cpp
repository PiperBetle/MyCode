#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
struct circle
{
	int x,y,r;
}a[107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	int x1,x2,y1,y2;
	int t1,t2,t3;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x;
	for(i=1;i<=n;i++)cin>>a[i].y;
	for(i=1;i<=n;i++)cin>>a[i].r;
	cin>>x1>>y1>>x2>>y2;
	for(i=1;i<=n;i++)
	{
		t1=(a[i].x-x1)*(a[i].x-x1)+(a[i].y-y1)*(a[i].y-y1);
		t2=(a[i].x-x2)*(a[i].x-x2)+(a[i].y-y2)*(a[i].y-y2);
		a[i].r=a[i].r*a[i].r;
		if(((t1<a[i].r)&&(a[i].r<t2))||((t2<a[i].r)&&(a[i].r<t1)))ans++;
	}
	cout<<ans;
	
    return 0;
}
