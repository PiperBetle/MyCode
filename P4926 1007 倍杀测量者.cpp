#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define eps 1e-4
using std::cin;using std::cout;
struct line{int opt,u,v;double t;line(int opt,int u,int v,double t){this->opt=opt,this->u=u,this->v=v,this->t=t;}};
std::vector<line>e;
struct edge{int go;double data;edge(int go,double data){this->go=go,this->data=data;}};
std::vector<edge>s[1007];
double dis[1007],score[1007];
int n,m,k,cnt[1007];
bool vis[1007];
std::queue<int>q;
inline bool check(double x)
{
	int i,now;
	while(!q.empty())q.pop();
	for(i=0;i<=n;i++)s[i].clear(),dis[i]=1.0,vis[i]=false,cnt[i]=0,q.push(i);
	for(auto it:e)
		if(it.opt==1)s[it.u].emplace_back(it.v,it.t-x);
		else s[it.u].emplace_back(it.v,1.0/(it.t+x));
	for(i=1;i<=n;i++)if(score[i]>0)
		s[0].emplace_back(i,score[i]),s[i].emplace_back(0,1.0/score[i]);
	while(!q.empty())
	{
		vis[now=q.front()]=false;q.pop();
		for(auto it:s[now])if(dis[it.go]<dis[now]*it.data)
		{
			dis[it.go]=dis[now]*it.data;
			if(!vis[it.go])
			{
				vis[it.go]=true;
				q.push(it.go);
				if(++cnt[it.go]>n+1)return 0;
			}
		}
	}
	return 1;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int opt,u,v;
	double t,l=0.0,r=1e7,ans=-1,mid;
	scanf("%d%d%d",&n,&m,&k);
	while(m--)scanf("%d%d%d%lf",&opt,&v,&u,&t),e.emplace_back(opt,u,v,t);
	while(k--)scanf("%d%lf",&opt,&t),score[opt]=t;
	while(l+eps<r)
		if(!check(mid=(l+r)/2.0))ans=l=mid;
		else r=mid;
	if(ans<0)printf("-1");else printf("%.6lf",ans);
	return 0;
}