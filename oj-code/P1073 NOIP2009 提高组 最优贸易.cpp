#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
std::vector<int>s[100007];
int a[100007],n,m,ans=0;
bool vis[100007][107][3];
void dfs(int now,int data,int type){
	cout<<now<<' '<<data<<' '<<type<<'\n';
	if(now==n&&type==2){ans=std::max(ans,data);return;}
	if(vis[now][data][type])return;else vis[now][data][type]=true;
	if(type==0)for(auto it:s[now])dfs(it,0,0),dfs(it,a[now],1);
	else if(type==1)for(auto it:s[now]){dfs(it,data,1);if(a[now]-data>ans)dfs(it,a[now]-data,2);}
	else for(auto it:s[now])dfs(it,now,2);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,u,v,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++){
		cin>>u>>v>>t;
		s[u].emplace_back(v);
		if(t==2)s[v].emplace_back(u);
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}