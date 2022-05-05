#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define int long long
using std::cin;using std::cout;
struct edge{int go,data;};
struct tree{std::vector<edge>data;}a[100007];
int sum,ans,dis[100007];
inline void dfs(int now,int step)
{
	dis[now]=step;
	for(auto it:a[now].data)if(dis[it.go]==0x3f3f3f3f3f3f3f3f)
		dfs(it.go,step+it.data);
}
signed main()
{
	// freopen("travel.in","r",stdin);
	// freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int u,v,t;
	
	memset(dis,0x3f,sizeof dis);
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v>>t;
		if(v!=1)a[u].data.emplace_back((edge){v,t});
		if(u!=1)a[v].data.emplace_back((edge){u,t});
		sum+=t;
	}
	sum<<=1;dis[1]=0;dfs(1,0);
	for(i=1;i<=n;i++)ans=std::max(ans,dis[i]);
	cout<<sum-ans;
	
	return 0;
}