#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define eps 1e-6
using std::cin;using std::cout;
struct point{double x,y;}a[107];
int f[107],n;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x,int y){x=find(x);y=find(y);if(x!=y)f[x]=y;}
bool check(double k){
	for(int i=0;i<=n+1;i++)f[i]=i;
	for(int i=1;i<=n;i++)if(100.0-a[i].y<k*2)merge(0,i);
	for(int i=1;i<=n;i++)if(100.0+a[i].y<k*2)merge(n+1,i);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		if(fabs(a[i].x-a[j].x)*fabs(a[i].x-a[j].x)+fabs(a[i].y-a[j].y)*fabs(a[i].y-a[j].y)<k*k*4)
			merge(i,j);
	return find(0)!=find(n+1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	double l=0.0,r=100.0;
	while(r-l>eps){
		double mid=(l+r)/2.0;
		if(check(mid))l=mid;else r=mid;
	}
	cout<<l;
	return 0;
}