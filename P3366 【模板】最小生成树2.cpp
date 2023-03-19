#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
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
	int n,m,cnt=0;
	int u,v,t,ans=0;
	
	for(i=0;i<1000007;i++)f[i]=i;
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].t;
	std::sort(a+1,a+1+m,[](edge x,edge y){return x.t<y.t;});
	for(i=1;i<=m;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){ans+=a[i].t;f[fx]=fy;cnt++;}
		if(cnt==n-1)return cout<<ans,0;
	}
	cout<<"orz";

	return 0;
}