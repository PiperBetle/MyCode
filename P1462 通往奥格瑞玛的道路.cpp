#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
struct point{int id,dis;bool operator<(const point&n)const{return dis>n.dis;}};
__gnu_pbds::priority_queue<point>q;
struct edge{int go,data;};
std::vector<edge>s[10007];
using std::cin;using std::cout;
int f[10007],dis[10007],vis[10007],n,m,b;
bool check(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	for(dis[1]=0,q.push(point{1,0});!q.empty();){
		int u=q.top().id;q.pop();
		if(vis[u])continue;else vis[u]=true;
		for(auto v:s[u])if(dis[v.go]>dis[u]+v.data&&f[v.go]<=x)
			dis[v.go]=dis[u]+v.data,q.push(point{v.go,dis[v.go]});
	}
	return dis[n]<=b;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,u,v,t,ans=-1;
	cin>>n>>m>>b;
	for(i=1;i<=n;i++)cin>>f[i];
	for(i=1;i<=m;i++){cin>>u>>v>>t;if(u!=v)s[u].emplace_back(edge{v,t}),s[v].emplace_back(edge{u,t});}
	int l=std::max(f[1],f[n]),r=1000000000,mid;
	while(l<=r)if(check(mid=(l+r)>>1))ans=mid,r=mid-1;else l=mid+1;
	if(ans==-1)cout<<"AFK";else cout<<ans;
	return 0;
}