#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct edge{int go,data,next;}a[1000007];
int head[1000007],dis[1000007],l=0,pre[1000007];bool visit[1000007];
void add(int u,int v,int t){l++;a[l].data=t;a[l].go=v;a[l].next=head[u];head[u]=l;}
struct road{int dis,ID;bool operator<(const road &n)const{return dis>n.dis;}};
std::priority_queue<road>q;std::vector<int>s;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,start=1;
	int u,v,t;
	
	cin>>n>>m;
	memset(dis,0x3f,sizeof dis);
	for(i=1;i<=m;i++)cin>>u>>v>>t,add(u,v,t),add(v,u,t);
	dis[start]=0;
	q.push((road){0,start});
	while(!q.empty())
	{
		road now=q.top();q.pop();
		if(visit[now.ID])continue;visit[now.ID]=1;
		for(i=head[now.ID];i;i=a[i].next)
			if(dis[a[i].go]>dis[now.ID]+a[i].data)
			{
				dis[a[i].go]=dis[now.ID]+a[i].data;
				pre[a[i].go]=now.ID;
				if(!visit[a[i].go])q.push((road){dis[a[i].go],a[i].go});
			}
	}
	if(!(dis[n]^0x3f3f3f3f3f3f3f3f))return cout<<-1,0;
	int now=n;cout<<1;
	while(pre[now])s.emplace_back(now),now=pre[now];
	for(i=s.size()-1;i>=0;i--)cout<<' '<<s[i];cout<<'\n';
	
	return 0;
}