#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[2007][2007];
int n=0,m,ans[200007],cnt[200007];
void dfs(int now)
{
	for(int i=1;i<=n;i++)
	{
		if(f[now][i]<1)continue;
		f[now][i]--;f[i][now]--;
		dfs(i);
	}
	ans[++ans[0]]=now;
} 
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int u,v,begin=1;

	cin>>m;
	for(;m--;cin>>u>>v,f[u][v]++,f[v][u]++,cnt[u]++,cnt[v]++,n=max(n,max(u,v)));
	for(i=1;i<=n;i++)if(cnt[i]&1){begin=i;break;}
	dfs(begin);
	for(;ans[0]>=1;cout<<ans[ans[0]--]<<'\n');
	
	return 0;
}