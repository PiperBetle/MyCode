#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
std::vector<int>s[17];
int in[17],topo[17];
std::queue<int>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j;
	int n,T;
	char c;

	cin>>T;while(T--)
	{
		memset(in,0,sizeof in);
		memset(topo,0,sizeof topo);
		while(!q.empty())q.pop();
		cin>>n;
		for(i=0;i<=n;i++)s[i].clear();
		for(i=1;i<=n;i++)for(j=i;j<=n;j++)
			if(cin>>c;c=='+')s[i-1].emplace_back(j),in[j]++;
			else if(c=='-')s[j].emplace_back(i-1),in[i-1]++;
		for(i=0;i<=n;i++)if(!in[i])q.emplace(i);
		int cnt=0;
		while(!q.empty())
		{
			int now=q.front();q.pop();
			cnt++;
			for(auto it:s[now])
				if(!--in[it])q.emplace(it),topo[it]=cnt;
		}
		for(i=1;i<=n;i++)cout<<topo[i]-topo[i-1]<<' ';
		cout<<'\n';
	}
	
	return 0;
}