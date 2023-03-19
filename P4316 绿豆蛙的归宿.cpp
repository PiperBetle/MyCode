#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
std::queue<int>q;
struct edge{int go;double data;};
std::vector<edge>s[100007];
int in[100007],cnt[100007];
double f[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,n,m,u,v;double t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)scanf("%d%d%lf",&u,&v,&t),s[v].emplace_back(edge{u,t}),in[u]++,cnt[u]++;
	while(!q.empty())q.pop();
	q.push(n);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(auto it:s[now])
		{
			f[it.go]+=(f[now]+it.data)/cnt[it.go];
			if(!--in[it.go])q.push(it.go);
		}
	}
	printf("%.2lf",f[1]);
	return 0;
}