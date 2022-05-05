#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define big 715827882
#define BIG 715827882
using namespace std;
struct qw
{
	int x,y,z;
};
int f[101];
int cmp(const qw &a,const qw &b)
{
	if(a.z<=b.z)return 1;
	return 0;
}
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
qw a[5001];
inline int read()
{
	int xx=0,yy=1;
	char chch=getchar();
	while(chch<'0'||chch>'9')
	{
		if(chch=='-')
			yy=-1;
		chch=getchar();
	}
	while(chch>='0'&&chch<='9')
	{
		xx=(xx<<1)+(xx<<3)+(chch^48);
		chch=getchar();
	}
	return xx*yy;
}
int main()
{
	int n=read(),m=read(),x,y,i,j,k=0,ans=0;
	int fx,fy;
	
	for(i=1;i<=m;i++)
	{
		a[i].x=read();
		a[i].y=read();
		a[i].z=read();
		ans+=a[i].z;
	}
	for(i=1;i<=n;i++)f[i]=i;
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++)
	{
		fx=find(a[i].x);
		fy=find(a[i].y);
		if(fx!=fy)
		{
			f[fx]=fy;
			k++;
			ans-=a[i].z;
		}
		if(k==m-1)break;
	}
	printf("%d",ans);
	
	return 0;
}
