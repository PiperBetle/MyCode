#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
std::vector<int>s[100007];
int n,col[100007],size[100007],cnt[100007],ans[100007],moc,sum;
bool g_son[100007];
using std::cin;using std::cout;
void get_g(int now,int fa,int max_son=0){
	size[now]=1;
	for(auto it:s[now])if(it!=fa){
		get_g(it,now);
		size[now]+=size[it];
		if(size[it]>size[max_son])max_son=it;
	}
	if(max_son)g_son[max_son]=true;
}
void clear(int now,int fa){
	cnt[col[now]]--;
	for(auto it:s[now])if(it!=fa)clear(it,now);
}
void g_dfs(int now,int fa,int max_son){
	if(++cnt[col[now]]>moc)moc=cnt[col[now]],sum=col[now];
	else if(cnt[col[now]]==moc)sum+=col[now];
	for(auto it:s[now])if(it!=fa&&it!=max_son)g_dfs(it,now,max_son);
}
void dfs(int now,int fa,int max_son=0){
	for(auto it:s[now])if(it!=fa){
		if(g_son[it]){max_son=it;continue;}
		dfs(it,now);
		clear(it,now);
		moc=sum=0;
	}
	if(max_son)dfs(max_son,now);
	g_dfs(now,fa,max_son);
	ans[now]=sum;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,u,v;
	cin>>n;
	for(i=1;i<=n;i++)cin>>col[i];
	for(i=1;i<n;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	get_g(1,0);
	dfs(1,0);
	for(i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}