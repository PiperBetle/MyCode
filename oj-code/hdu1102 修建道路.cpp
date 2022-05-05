#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int f[1007];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
struct road
{
	int u,v,t;
}a[1000007];
bool cmp(road _x,road _y)
{
	return _x.t<_y.t;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k=0;
	int n,m,q,T,l=0;
	int x,y,ans=0;
	
	cin>>n;
	for(i=0;i<1007;i++)f[i]=i;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)cin>>k;
			else
			{
				l++;
				a[l].u=i;
				a[l].v=j;
				cin>>a[l].t;
			}
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		f[find(x)]=find(y);
		k++;
	}
	sort(a+1,a+1+l,cmp);
	for(i=1;i<=l;i++)
	{
		if(k==n-1)break;
		int fx=find(a[i].u);
		int fy=find(a[i].v);
		if(fx!=fy)
		{
			ans+=a[i].t;
			f[fx]=fy;
			k++;
		}
	}
	cout<<ans;
	
	return 0;
}
