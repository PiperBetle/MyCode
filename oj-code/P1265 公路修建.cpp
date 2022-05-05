#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline double max(double x,double y){return x>y?x:y;}
inline double min(double x,double y){return x<y?x:y;}
inline double abs(double x){return x>0?x:-x;}
inline double sqr(double x){return x*x;}
struct point{double x,y;};
inline double dis(point a,point b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
point a[10007];
bool b[10007];
double f[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	double ans=0.0;
	
	for(i=0;i<10007;i++)f[i]=1e100;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	f[1]=0;b[1]=1;
	for(i=1;i<=n;i++)
	{
		int p=1;double minn=1e100;
		for(j=1;j<=n;j++)if(!b[j]&&f[j]<minn)minn=f[j],p=j;
		b[p]=1;ans+=sqrt(f[p]);
		for(j=1;j<=n;j++)f[j]=min(f[j],dis(a[p],a[j]));
	}
	printf("%.2f",ans);
	
	return 0;
}
