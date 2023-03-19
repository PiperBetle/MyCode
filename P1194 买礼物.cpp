#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MAXN 500007
using namespace std;
struct kru
{
	int u,v,t;
}a[MAXN];
inline int cmp(kru x,kru y)
{
	return x.t<y.t;
}
int f[MAXN];
inline int find(int x)
{
	if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}
int main()
{
	int n=0,m,T,t;
	int i,j,k;
	int x,y;
	int ans=0,sum=0;
	
	for(i=0;i<MAXN;i++)f[i]=i;
	scanf("%d%d",&T,&m);
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
		{
			cin>>t;
			if(i<=j&&t!=0)
			{
				n++;
				a[n].t=t;
				a[n].u=i;
				a[n].v=j;
			}
		}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)
	{
		x=find(a[i].u);
		y=find(a[i].v);
		if(x!=y)
		{
			f[x]=y;
			if(a[i].t<T)ans+=a[i].t;
			else ans+=T;
		}
	}
	cout<<ans+T;
	
	return 0;
}
