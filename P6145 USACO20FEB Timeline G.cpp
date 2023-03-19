#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[100007];
int dis[100007];
bool visit[100007];
std::queue<int>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,c;
	int x1,x2,y1;
	
	memset(dis,-0x3f,sizeof dis);
	while(!q.empty())q.pop();
	cin>>n>>m>>c;
	for(i=1;i<=n;i++)cin>>y1,s[0].emplace_back((edge){i,y1});
	for(i=1;i<=c;i++)cin>>x1>>x2>>y1,s[x1].emplace_back((edge){x2,y1});
	for(i=1;i<=n;i++)s[0].emplace_back((edge){i,0});
	q.push(0);visit[0]=1;dis[0]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		visit[now]=0;
		for(auto it:s[now])
			if(dis[it.go]<dis[now]+it.data)
			{
				dis[it.go]=dis[now]+it.data;
				if(!visit[it.go])q.push(it.go),visit[it.go]=1;
			}
	}
	for(i=1;i<=n;i++)cout<<dis[i]<<'\n';
	
	return 0;
}