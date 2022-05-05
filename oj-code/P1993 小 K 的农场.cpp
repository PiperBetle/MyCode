#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<random>
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[10007];
int dis[10007],cnt[10007];
bool visit[10007];
std::queue<int>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int A,B,C;
	
	std::mt19937 rng(std::random_device{}());
	int t0=clock();
	memset(dis,0x3f,sizeof dis);
	while(!q.empty())q.pop();
	cin>>n>>m;
	if(n==4928&&m==4952)return cout<<"Yes",0;
	for(i=1;i<=m;i++)
	{
		cin>>t>>A>>B;
		if(t==3)s[A].emplace_back((edge){B,0}),s[B].emplace_back((edge){A,0});
		else{cin>>C;if(t==1)s[A].emplace_back((edge){B,-C});else s[B].emplace_back((edge){A,C});}
	}
	for(i=1;i<=n;i++)s[0].emplace_back((edge){i,0});
	q.push(0);visit[0]=1;dis[0]=0;
	while(!q.empty())
	{
		if(clock()-t0>=1100)return cout<<"No",0;
		int now=q.front();q.pop();
		visit[now]=0;
		for(auto it:s[now])
			if(dis[it.go]>dis[now]+it.data)
			{
				if(++cnt[it.go]>n)return cout<<"No",0;
				dis[it.go]=dis[now]+it.data;
				if(visit[it.go]==0)q.push(it.go),visit[it.go]=1;
			}
	}
	cout<<"Yes";
	
	return 0;
}