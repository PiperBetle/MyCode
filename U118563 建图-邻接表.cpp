#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int head[1000005],go[1000005],cost[1000005],next[1000005],l=0;
void add(int u,int v,int w)
{
	next[++l]=head[u];
	go[l]=v;
	cost[l]=w;
	head[u]=l;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int u,v,t,n,m;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>t;
		add(u,v,t);
	}
	for(i=1;i<=n;i++)
	{
		cout<<i<<":\n";
		for(j=head[i];j;j=next[j])
			cout<<go[j]<<' '<<cost[j]<<endl;
	}
	return 0;
}
