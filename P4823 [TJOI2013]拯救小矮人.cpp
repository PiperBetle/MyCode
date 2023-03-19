#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct people
{
	int x,y;
	bool operator<(const people &n)const
	{
		if(x+y==n.x+n.y)return x<n.x;
		return x+y<n.x+n.y;
	}
}a[100007];
int f[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	memset(f,-0x3f,sizeof f);
	f[0]=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	cin>>m;
	std::sort(a+1,a+1+n);
	for(i=1;i<=n;i++)f[0]+=a[i].x;
	for(i=1;i<=n;i++)for(j=i;j>=1;j--)
		if(f[j-1]+a[i].y>=m)f[j]=max(f[j],f[j-1]-a[i].x);
	for(i=n;i>=0;i--)
		if(f[i]>=0)return cout<<i,0;
	
	return 0;
}
