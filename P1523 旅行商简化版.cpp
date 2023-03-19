#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline double max(double x,double y){return x>y?x:y;}
inline double min(double x,double y){return x<y?x:y;}
inline double abs(double x){return x>0?x:-x;}
inline double sqr(double x){return x*x;}
struct point{double x,y;bool operator<(const point n){return x<n.x;}}a[1007];
inline double dis(point a,point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
double f[1007][1007],d[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	for(i=0;i<1007;i++)for(j=0;j<1007;j++)f[i][j]=1e100;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	std::sort(a+1,a+1+n);
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)d[i][j]=d[j][i]=dis(a[i],a[j]);
	f[1][2]=d[1][2];
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)
		f[i][j+1]=min(f[i][j+1],f[i][j]+d[j][j+1]),
		f[j][j+1]=min(f[j][j+1],f[i][j]+d[i][j+1]);
	double ans=1e100;
	for(i=1;i<n;i++)ans=min(ans,f[i][n]+d[i][n]);
	printf("%.2f",ans);

	return 0;
}
