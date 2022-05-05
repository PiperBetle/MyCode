#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
std::vector<int>s[5007];
std::queue<int>q;
int in[5007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,flag=0;
	int u,v,t=0;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>u>>v,s[u].emplace_back(v),in[v]++;
	for(i=1;i<=n;i++)if(!in[i])q.emplace(i),t++;
	if(t>1)flag=1;t=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		cout<<now<<'\n';t=0;
		for(auto it:s[now])
			if(--in[it]==0)q.emplace(it),t++;
		if(t>1)flag=1;
	}
	cout<<flag;
	
	return 0;
}