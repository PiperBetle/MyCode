#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
std::vector<int>s[40007];
int dis[40007][4],n,m;
std::queue<int>q;
inline void bfs(int begin)
{
	while(!q.empty())q.pop();
	q.emplace(begin);
	int l=(begin==n?3:begin);dis[begin][l]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(auto it=s[now].begin();it!=s[now].end();it++)
			if(dis[*it][l]==0xffff)dis[*it][l]=dis[now][l]+1,q.emplace(*it);
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int B,E,P;
	int u,v,ans=1e9;

	cin>>B>>E>>P>>n>>m;P=min(P,B+E);
	for(i=1;i<=m;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	for(i=0;i<40007;i++)for(j=0;j<4;j++)dis[i][j]=0xffff;
	bfs(1);bfs(2);bfs(n);
	for(i=1;i<=n;i++)ans=min(ans,B*dis[i][1]+E*dis[i][2]+P*dis[i][3]);
	cout<<ans;

	return 0;
}