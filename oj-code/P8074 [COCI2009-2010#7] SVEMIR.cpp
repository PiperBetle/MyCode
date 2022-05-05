#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct point{int x,y,z,ID;int operator-(const point &n)const{return min(abs(x-n.x),min(abs(y-n.y),abs(z-n.z)));}}a[1000007];
inline bool cmp1(point a,point b){return a.x<b.x;}
inline bool cmp2(point a,point b){return a.y<b.y;}
inline bool cmp3(point a,point b){return a.z<b.z;}
struct edge{int u,v,data;bool operator<(const edge &n)const{return data<n.data;}}s[1000007];
int f[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=0,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z,a[i].ID=i;
	std::sort(a+1,a+1+n,cmp1);for(i=1;i<n;i++)s[++m].u=a[i].ID,s[m].v=a[i+1].ID,s[m].data=a[i]-a[i+1];
	std::sort(a+1,a+1+n,cmp2);for(i=1;i<n;i++)s[++m].u=a[i].ID,s[m].v=a[i+1].ID,s[m].data=a[i]-a[i+1];
	std::sort(a+1,a+1+n,cmp3);for(i=1;i<n;i++)s[++m].u=a[i].ID,s[m].v=a[i+1].ID,s[m].data=a[i]-a[i+1];
	for(i=0;i<1000007;i++)f[i]=i;std::sort(s+1,s+1+m);
	for(i=1;;i++)
	{
		int fx=find(s[i].u),fy=find(s[i].v);
		if(fx==fy)continue;
		f[fx]=fy;ans+=s[i].data;
		n--;if(n==1)return cout<<ans,0;
	}
}
