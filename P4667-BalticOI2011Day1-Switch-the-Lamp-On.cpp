#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define s(a,b) ((a-1)*(m+1)+(b))
using namespace std;
struct road
{
	int go,cost,next;
};
road a[1000007];
int head[1000007],dis[1000007],l=0;
bool visit[1000007];
void add(int u,int v,int t)
{
	l++;
	a[l].cost=t;
	a[l].go=v;
	a[l].next=head[u];
	head[u]=l;
}
struct qw
{
	int dis,id;
	friend bool operator<(const qw a,const qw b)
	{   
		return a.dis>b.dis;
	}
};
priority_queue<qw> q;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m;
	int u,v,t;
	char c;
	qw EP;
	
	cin>>n>>m;
	memset(dis,0x3f,sizeof dis);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>c;
			if(c=='\\')
			{
				add(s(i,j),s(i+1,j+1),0);
				add(s(i+1,j+1),s(i,j),0);
				add(s(i+1,j),s(i,j+1),1);
				add(s(i,j+1),s(i+1,j),1);
			}
			else
			{
				add(s(i,j),s(i+1,j+1),1);
				add(s(i+1,j+1),s(i,j),1);
				add(s(i+1,j),s(i,j+1),0);
				add(s(i,j+1),s(i+1,j),0);
			}
		}
	dis[1]=0;
	EP.dis=0;
	EP.id=1;
	q.push(EP);
	while(!q.empty())
	{
		EP=q.top();
		q.pop();
		int ID=EP.id,DIS=EP.dis;
		if(visit[ID])continue;
		visit[ID]=1;
		for(i=head[ID];i;i=a[i].next)
		{
			int to=a[i].go;
			if(dis[to]>dis[ID]+a[i].cost)
			{
				dis[to]=dis[ID]+a[i].cost;
				if(!visit[to])
				{
					EP.dis=dis[to];
					EP.id=to;
					q.push(EP);
				}
			}
		}
	}
	cout<<dis[s(n,m)]<<'\n';
	
	return 0;
}
