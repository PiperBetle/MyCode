#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[1007];
struct qw{int x,y;}a[1007];
bool cmp(struct qw x,struct qw y)
{
	if(x.x!=y.x) return x.x<y.x;
	return x.y<y.y;
}
int main()
{
	int i,j,k,ans;
	int n,m;
	
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
	{
		f[i]=1;
		for(j=1;j<i;j++)
			if(a[i].x>a[j].x&&a[i].y>a[j].y)
				f[i]=max(f[i],f[j]+1);
		ans=max(ans,f[i]);
	}
	double t=(n+m-2*ans)*100;
	double p=141.42135623730950488016887242097*ans;
	p=p+t;
	printf("%d",int(p+0.5));
	
	return 0;
}
