#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#define int long long
using std::cin;using std::cout;
int f[300007][37],in[300007];
std::vector<int>s[300007];
std::string a;
std::queue<int>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=1;
	int u,v,cnt=0;
	
	cin>>n>>m>>a;a=' '+a;
	for(i=1;i<=n;i++)f[i][a[i]-'a'+1]=1;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		if(u==v)return cout<<"-1",0;
		s[u].emplace_back(v);
		in[v]++;
	}
	for(i=1;i<=n;i++)if(!in[i])q.push(i);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		cnt++;
		for(auto it:s[now])
		{
			for(j=1;j<=26;j++)
				if(j==a[it]-'a'+1)ans=std::max(ans,f[it][j]=std::max(f[it][j],f[now][j]+1));
				else ans=std::max(ans,f[it][j]=std::max(f[it][j],f[now][j]));
			if(--in[it]==0)q.push(it);
		}
	}
	if(cnt!=n)cout<<"-1";else cout<<ans;
	
	return 0;
}