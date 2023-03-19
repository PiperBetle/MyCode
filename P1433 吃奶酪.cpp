#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define int long long
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct point
{
	double x,y;
}a[107];
double f[100007][107];
double dis(point x,point y)
{
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	memset(f,127,sizeof f);
	double ans=f[0][0];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		f[1<<(i-1)][i]=dis(a[0],a[i]);
	}
	for(k=1;k<(1<<n);k++)
		for(i=1;i<=n;i++)
			if(k&(1<<(i-1)))
				for(j=1;j<=n;j++)
					if(i!=j&&(k&(1<<(j-1))))
						f[k][i]=min(f[k][i],f[k-(1<<(i-1))][j]+dis(a[i],a[j]));
	for(i=1;i<=n;i++)
		ans=min(ans,f[(1<<n)-1][i]);
	printf("%.2f",ans);
	
    return 0;
}
