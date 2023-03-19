#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using std::cin;using std::cout;
struct edge{int u,v;};
std::vector<edge>e;
std::vector<int>s[200007];
std::queue<int>q;
int in[200007],topo[200007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int u,v,t;
	
	cin>>T;while(T--)
	{
		e.clear();
		cin>>n>>m;
		for(i=1;i<=m;i++)
		{
			cin>>t>>u>>v;
			if(!t)e.emplace_back((edge){u,v});
			else s[u].emplace_back(v),in[v]++;
		}
		for(i=1;i<=n;i++)if(!in[i])q.emplace(i);
		int cnt=0;
		while(!q.empty())
		{
			int now=q.front();q.pop();
			topo[now]=++cnt;
			for(auto it:s[now])
				if(--in[it]==0)q.push(it);
		}
		if(cnt!=n){cout<<"NO\n";for(i=1;i<=n;i++)s[i].clear(),in[i]=0,topo[i]=0x3f3f3f3f;continue;}
		cout<<"YES\n";
		for(i=1;i<=n;s[i++].clear())for(auto it:s[i])cout<<i<<' '<<it<<'\n';
		for(auto it:e)if(topo[it.u]>topo[it.v])cout<<it.v<<' '<<it.u<<'\n';else cout<<it.u<<' '<<it.v<<'\n';
	}
	
	return 0;
}