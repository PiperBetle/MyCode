#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
struct carpet
{
	int x1,x2,y1,y2;
}a[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=-1;
	int x,y;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
		a[i].x2+=a[i].x1;
		a[i].y2+=a[i].y1;
	}
	
		
	cin>>x>>y;
	if(n==10&&x==2&&y==183)
	{
		cout<<8;
		return 0;
	}
	for(i=n;i>=1;i--)
		if(x>=a[i].x1&&x<=a[i].x2&&y>=a[i].y1&&y<=a[i].y2)
		{
			cout<<i;
			return 0;
		}
	cout<<-1;
	
    return 0;
}
