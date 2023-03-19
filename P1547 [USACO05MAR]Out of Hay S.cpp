#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct kru
{
	int u,v,t;
}a[100007];
inline int cmp(kru x,kru y)
{
	return x.t<y.t;
}
int f[100007];
inline int find(int x)
{
	if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}
int main()
{
	int _1,_2,_3;
	int n,m,T;

	for(int register i=0;i<100007;i++)f[i]=i;
	scanf("%d%d",&n,&m);
	for(int register i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].t);
	sort(a+1,a+1+m,cmp);
	int ans=0,sum=0;
	for(int register i=1;i<=m;i++)
	{
		int x=find(a[i].u);
		int y=find(a[i].v);
		if(x!=y)
		{
			f[x]=y;
			sum++;
			ans=max(ans,a[i].t);
			if(sum==n-1)break;
		}
	}
	cout<<ans;

	
	return 0;
}
