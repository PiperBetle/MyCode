#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
std::vector<int>s[200007];
int d[200007],f[200007];
bool b[200007],ans[200007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k=0;
	int n,m,t;
	int u,v;
	
	for(i=0;i<200007;i++)f[i]=i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		s[u].emplace_back(v);
		s[v].emplace_back(u);
	}
	for(i=1;i<=n;i++)cin>>d[i];
	for(i=n;i>=1;i--)
	{
		b[d[i]]=1;
		for(j=s[d[i]].size()-1;j>=0;j--)
		{
			if(!b[s[d[i]][j]])continue;
			int fx=find(d[i]),fy=find(s[d[i]][j]);
			if(fx!=fy){k++;f[fx]=fy;}
		}
		ans[i]=(k==n-i);
	}
	for(i=1;i<=n;i++)cout<<(ans[i]?"YES\n":"NO\n");
	
	return 0;
}
