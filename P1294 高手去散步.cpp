#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int n,m,b[1007],ans=0;
std::vector<std::pair<int,int> >s[107];
void dfs(int now,int step)
{
	ans=max(ans,step);
	for(auto it=s[now].begin();it!=s[now].end();it++)
		if(b[it->first]==0)
		{
			b[it->first]=1;
			dfs(it->first,step+it->second);
			b[it->first]=0;
		}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		int u,v,t;
		cin>>u>>v>>t;
		s[u].emplace_back(std::make_pair(v,t));
		s[v].emplace_back(std::make_pair(u,t));
	}
	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof b);
		b[i]=1;
		dfs(i,0);
	}
	cout<<ans;
	
	return 0;
}