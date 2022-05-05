#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int fa[10007];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int c[10007],d[10007],f[10007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y,w;
	
	for(i=0;i<10007;i++)fa[i]=i;
	cin>>n>>m>>w;
	
	for(i=1;i<=n;i++)cin>>c[i]>>d[i];
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		fa[find(x)]=find(y);
	}
	for(i=1;i<=n;i++)
		if(find(i)!=i)
		{
			c[find(i)]+=c[i];
			d[find(i)]+=d[i];
			c[i]=d[i]=0;
		}
	for(i=1;i<=n;i++)
	    if(c[i]!=0)
			for(j=w;j>=c[i];j--)
	    		f[j]=max(f[j],f[j-c[i]]+d[i]);
	cout<<f[w];
	
	return 0;
}
