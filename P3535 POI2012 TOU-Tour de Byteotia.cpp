#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline void swap(int &x,int &y){x^=y;y^=x;x^=y;}
int f[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void un(int x,int y){int fx=find(x),fy=find(y);if(fx!=fy)f[fx]=fy;}
struct point{int x,y;}a[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y,ans=0;

	for(i=0;i<1000007;i++)f[i]=i;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y;
		if(a[i].x>k&&a[i].y>k)un(a[i].x,a[i].y);
	}
	for(i=1;i<=m;i++)
	{
		if(a[i].x>k&&a[i].y>k)continue;
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy)un(a[i].x,a[i].y);else ans++;
	}
	cout<<ans;

	return 0;
}