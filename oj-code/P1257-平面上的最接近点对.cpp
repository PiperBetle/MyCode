#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
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
point a[400007],t[200007];
void ms(int l,int r)
{
	if(l>=r)return;
	int m=(l+r)>>1;
	ms(l,m);
	ms(m+1,r);
	inplace_merge(a+l,a+m,a+r,less<point>());
}
inline bool cmp(point x,point y){return x.y<y.y;}
void mst(int l,int r)
{
	if(l>=r)return;
	int m=(l+r)>>1;
	ms(l,m);
	ms(m+1,r);
	inplace_merge(t+l,t+m,t+r,cmp);
}
int find(int l,int r)
{
	if(l>=r)return 1e16;
	if(l+1==r)
	{
		if(a[l].y>a[r].y)
			swap(a[l],a[r]);
		return dis(a[l],a[r]);
	}
	int m=(l+r)>>1,lt=0,x=a[m].x,d=MIN(find(l,m),find(m+1,r));
	// ms(l,r);
	for(int i=l;i<=r;i++)
		if((a[i].x-x)*(a[i].x-x)<d)
			t[++lt]=a[i];
	// mst(1,lt);
	sort(t+1,t+1+lt,cmp);
	for(int i=1;i<lt;i++)
		for(int j=i+1;j<=lt&&(t[i].y-t[j].y)*(t[i].y-t[j].y)<=d;j++)
			d=MIN(d,dis(t[i],t[j]));
	return d;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;

	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+n,less<point>());
	cout<<find(1,n)<<'\n';
	
	return 0;
}