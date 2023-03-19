#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
using namespace std;
struct point{int x,y;};
point a[57];
int f[57];
inline int dis(point x,point y){return ABS(x.x-y.x)+ABS(x.y-y.y);}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int left=0,right=1000000000,ans,mid;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	while(left+1<right)
	{
		for(i=0;i<57;i++)
			f[i]=i;
		mid=(left+right)>>1;
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
			{
				int d=dis(a[i],a[j]);
				if(d<=(mid<<1))
				{
					int fx=find(i),fy=find(j);
					if(fx!=fy)f[fx]=fy;
				}
			}
		int sum=0;
		for(i=1;i<=n;i++)
			sum+=(i==find(i));
		if(sum==1)ans=right=mid;
		else left=mid;
	}
	cout<<ans<<'\n';
	
	return 0;
}