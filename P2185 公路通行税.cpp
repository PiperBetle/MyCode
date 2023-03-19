#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
std::vector<int>s[1007];
int dis[1007];
std::queue<int>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int u,v,ans;
	
	while(cin>>n>>m)
	{
		if(!n&&!m)return 0;ans=0;
		for(i=0;i<1007;i++)s[i].clear();
		for(i=1;i<=m;i++)cin>>u>>v,s[u].push_back(v),s[v].push_back(u);
		for(i=1;i<=n;i++)
		{
			while(!q.empty())q.pop();
			memset(dis,0x3f,sizeof dis);dis[i]=0;
			q.push(i);
			do
			{
				int now=q.front();q.pop();
				for(j=s[now].size()-1;~j;j--)
					if(dis[s[now][j]]>1e9)dis[s[now][j]]=dis[now]+1,q.push(s[now][j]);
			}while(!q.empty());
			for(j=1;j<=n;j++)if(dis[j]<1e9)ans=max(ans,dis[j]);
		}
		cout<<ans*100<<'\n';
	}
	
	return 0;
}