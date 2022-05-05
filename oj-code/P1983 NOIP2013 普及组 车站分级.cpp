#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
bool visit[5007],f[5007][5007];
int a[5007],in[5007];
std::vector<int>s[5007];
struct point{int id,dis;};
std::queue<point>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,l;
	int t,ans=0;
	
	cin>>n>>m;
	while(m--)
	{
		memset(visit,0,sizeof visit);
		for(cin>>l,i=1;i<=l;i++)cin>>a[i],visit[a[i]]=1;
		for(i=a[1];i<=a[l];i++)if(!visit[i])for(j=1;j<=l;j++)if(!f[i][a[j]])
		{
			in[a[j]]++;
			f[i][a[j]]=1;
			s[i].emplace_back(a[j]);
		}
	}
	for(i=1;i<=n;i++)if(in[i]==0)q.push((point){i,1});
	while(!q.empty())
	{
		point now=q.front();q.pop();
		for(auto it:s[now.id])if(--in[it]==0)
			q.push((point){it,now.dis+1}),ans=std::max(ans,now.dis+1);
	}
	cout<<ans;
	
	return 0;
}