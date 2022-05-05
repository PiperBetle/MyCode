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
struct prod
{
	int x,y,PK,ID;
	bool operator<(const prod &n)const
	{
		if(PK!=n.PK)return PK<n.PK;
		if(PK<=0)return x<n.x;
		return y>n.y;
	}
}a[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int sa,sb;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x,a[i].ID=i;
	for(i=1;i<=n;i++)cin>>a[i].y,a[i].PK=(a[i].x==a[i].y?0:(a[i].x-a[i].y)/abs(a[i].x-a[i].y));
	std::sort(a+1,a+1+n);
	sa=a[1].x;sb=a[1].x+a[1].y;
	for(i=2;i<=n;i++)sb=max(sa+a[i].x,sb)+a[i].y,sa+=a[i].x;
	cout<<sb<<'\n';
	for(i=1;i<=n;i++)cout<<a[i].ID<<' ';

	return 0;
}