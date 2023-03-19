#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct point{int data;point *down,*right;};
point a[1007][1007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>n>>m>>T;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j].data;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			a[i][j].down=&a[i+1][j];
			a[i][j].right=&a[i][j+1];
		}
	while(T--)
	{
		int x1,x2,y1,y2,h,w;
		point *p1,*p2,*t1,*t2;
		cin>>x1>>y1>>x2>>y2>>h>>w;
		p1=p2=&a[0][0];
		while(--x1)p1=p1->down;
		while(--y1)p1=p1->right;
		while(--x2)p2=p2->down;
		while(--y2)p2=p2->right;
		t1=p1;t2=p2;
		for(i=1;i<=h;i++)
		{
			t1=t1->down;
			t2=t2->down;
			swap(t1->right,t2->right);
		}
		for(i=1;i<=w;i++)
		{
			p1=p1->right;
			p2=p2->right;
			swap(p1->down,p2->down);
		}
		for(i=1;i<=w;i++)
		{
			t1=t1->right;
			t2=t2->right;
			swap(t1->down,t2->down);
		}
		for(i=1;i<=h;i++)
		{
			p1=p1->down;
			p2=p2->down;
			swap(p1->right,p2->right);
		}
	}
	point *p=&a[0][0];
	p=p->down;
	for(i=1;i<=n;i++)
	{
		point *t=p;
		for(j=1;j<=m;j++)
		{
			t=t->right;
			cout<<t->data<<' ';
		}
		cout<<'\n';
		p=p->down;
	}
	
	return 0;
}