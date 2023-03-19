#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct edge{int next,to;}a[100007];
int head[100007],len,dep[100007],size[100007],ans[100007],f[100007],n;
inline void add(int u,int v){a[++len].to=v;a[len].next=head[u];head[u]=len;}
void find(int now)
{
	for(int i=head[now];i;i=a[i].next)
	{
		if(dep[a[i].to])continue;
		dep[a[i].to]=dep[now]+1;
		find(a[i].to);
		size[now]+=size[a[i].to];
	}
}
void dfs(int now,int fa)
{
	f[now]=f[fa]+n-(size[now]<<1);
	for(int i=head[now];i;i=a[i].next)
		if(a[i].to!=fa)dfs(a[i].to,now);
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int u,v;

	for(i=0;i<100007;i++)size[i]=1;
	cin>>n;
	for(i=1;i<n;i++){cin>>u>>v;add(u,v);add(v,u);}
	dep[1]=1;find(1);
	int ans=-n,ID=1;
	for(i=1;i<=n;i++)ans+=dep[i];
	f[1]=ans;
	for(i=head[1];i;i=a[i].next)dfs(a[i].to,1);
	for(i=2;i<=n;i++)if(ans>f[i])ans=f[i],ID=i;
	cout<<ID<<' '<<ans<<'\n';
	
	return 0;
}