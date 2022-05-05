#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
struct qw{int x,y,t;};
qw a[100007];
int n,m,f[100007];
int cmp(qw _x,qw _y){return _x.t<_y.t;}
int find(int x){return x==f[x]? x:f[x]=find(f[x]);}
int un(int x,int y){f[find(x)]=find(y);}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].t;
	for(i=1;i<=n;i++)f[i]=i;
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=m;i++)
	{
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy)
		{
			f[fx]=fy;
			n--;
		}
		if(n==1)
		{
			cout<<a[i].t;
			return 0;
		}
	}
	cout<<"-1";
	
	return 0;
}
