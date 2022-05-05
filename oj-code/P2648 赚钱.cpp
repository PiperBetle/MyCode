#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[307];
int dis[307],cnt[307];
bool visit[307];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,u,v,t,ans=0,m1,m2,d;
	cin>>d>>m1>>n>>m2;
	for(i=1;i<=m1;i++)cin>>u>>v,s[u].emplace_back(edge{v,d});
	for(i=1;i<=m2;i++)cin>>u>>v>>t,s[u].emplace_back(edge{v,d-t});
	for(i=1;i<=n;i++)s[0].emplace_back(edge{i,dis[i]=0});
	q.push(0);cnt[0]=1;dis[0]=d;
	while(!q.empty()){
		int now=q.front();q.pop();
		visit[now]=false;
		for(auto it:s[now])if(dis[it.go]<dis[now]+it.data){
			if(++cnt[it.go]>n)return cout<<"orz",0;
			dis[it.go]=dis[now]+it.data;
			if(visit[it.go]==0)q.push(it.go),visit[it.go]=true;
		}
	}
	for(i=1;i<=n;i++)ans=std::max(ans,dis[i]);
	cout<<ans;
	return 0;
}