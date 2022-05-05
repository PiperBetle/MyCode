#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
bool d[1000007];
struct edge{int u,v,t;}a[1000007];
int f[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int u,v,ans=0;
	
	for(i=0;i<1000007;i++)f[i]=i;
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>t,d[t]=1;
	for(i=1;i<n;i++)cin>>a[i].u>>a[i].v>>a[i].t,ans+=a[i].t;
	std::sort(a+1,a+1+n,[](edge x,edge y){return x.t>y.t;});
	for(i=1;i<n;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v);
		if(d[fx]&&d[fy])continue;
		f[fx]=fy;ans-=a[i].t;
		d[fx]=d[fy]=(d[fx]|d[fy]);
	}
	cout<<ans;
	
	return 0;
}