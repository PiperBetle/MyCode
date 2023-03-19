#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct cow
{
	int x,y;
	bool operator<(const cow &n)const
	{
		if(x<y)return n.x<n.y?x<n.x:1;
		else return n.x<n.y?0:y>n.y;
	}
}a[1000007];
int u[1000007],d[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	std::sort(a+1,a+1+n);
	for(i=1;i<=n;i++)u[i]=u[i-1]+a[i].x;
	for(i=1;i<=n;i++)d[i]=max(d[i-1],u[i])+a[i].y;
	cout<<d[n];
	
	return 0;
}
