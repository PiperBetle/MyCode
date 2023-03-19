#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct point
{
	int x,y;
};
point a[1007];
inline int dis(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,now,ans=1e9;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	for(i=1;i<=n;i++)
	{
		now=0;
		for(j=1;j<=n;j++)
			if(i!=j)now=max(now,dis(a[i],a[j]));
		ans=min(ans,now);
	}
	printf("%.4f",(double)ans*3.1415926535);
	
	return 0;
}
