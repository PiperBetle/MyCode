#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
using std::cin;using std::cout;
struct point{int id,dis;bool operator<(const point&n)const{return dis>n.dis;}};
__gnu_pbds::priority_queue<point>q;
struct edge{int go,data;};
std::vector<edge>s[2007];
int a[107],dis[2007],cnt[2007];
bool vis[2007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m,start,end,t;
	cin>>start>>end>>n;
	for(i=1;i<=n;i++){
		cin>>t>>m;
		for(j=1;j<=m;j++)cin>>a[j];
		for(j=1;j<m;j++)s[a[j]].emplace_back(edge{i+n,t});
		for(j=2;j<=m;j++)s[i+n].emplace_back(edge{a[j],0});
	}
	memset(dis,0x3f,sizeof dis);
	q.push(point{start,dis[start]=cnt[start]=0});
	while(!q.empty())
	{
		int u=q.top().dis;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto v:s[u])if(dis[v.go]>dis[u]+v.data){
			dis[v.go]>dis[u]+v.data;
			if(!vis[v.go])q.push(point{v.go,dis[v.go]});
		}
	}
	cout<<dis[end];
	return 0;
}
