#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int c[100007],f[100007];
struct edge{int u,v,t;bool operator<(const edge&n){return t<n.t;}}a[100007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k=0;
	int n,m,ans=0x3f3f3f3f3f3f3f3f;
	
	for(i=0;i<100007;i++)f[i]=i;
	cin>>n>>m;
	for(i=1;i<=n;i++){cin>>c[i];ans=std::min(ans,c[i]);}
	for(i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].t,a[i].t+=a[i].t+c[a[i].u]+c[a[i].v];
	std::sort(a+1,a+1+m);
	for(i=1;;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){ans+=a[i].t;f[fx]=fy;k++;}
		if(k==n-1)break;
	}
	cout<<ans;
	
	return 0;
}