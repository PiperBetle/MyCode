#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using namespace std;
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
struct point
{
	int x,y;
	bool operator <(const point &n)const
	{
		return x<n.x;
	}
};
inline int dis(point x,point y){return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);}
point a[200007],t[200007];
void ms(int l,int r)
{
	if(l>=r)return;
	int m=(l+r)>>1;
	ms(l,m);
	ms(m+1,r);
	inplace_merge(a+l,a+m,a+r,less<point>());
}
int find(int l,int r)
{
	if(l>=r)return 1e14;
	if(l+1==r)
	{
		if(a[l].y>a[r].y)
			swap(a[l],a[r]);
		return dis(a[l],a[r]);
	}
	int m=(l+r)>>1,lt=0,x=a[m].x,d=min(find(l,m),find(m+1,r));
	ms(l,r);
	for(int i=l;i<=r;i++)
		if((a[i].x-x)*(a[i].x-x)<d)
			t[++lt]=a[i];
	for(int i=1;i<lt;i++)
		// for(int j=i+1;j<=lt&&(t[i].y-t[j].y)*(t[i].y-t[j].y)<d;j++)
		for(int j=i+1;j<=lt;j++)
			d=min(d,dis(t[i],t[j]));
	return d;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;

	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+n,less<point>());
	double ans=sqrt(find(1,n));
	printf("%.4Lf\n",ans);
	
	return 0;
}