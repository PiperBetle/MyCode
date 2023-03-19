#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct edge{int go,next;}a[1000007];
int head[1000007],l,cnt[1000007],ans[1000007];
void add(int u,int v){a[++l].go=v;a[l].next=head[u];head[u]=l;}
std::priority_queue<int>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x,y;
	
	cin>>T;
	while(T--)
	{
		cin>>n>>m;l=0;k=n;
		while(!q.empty())q.pop();
		memset(head,0,sizeof head);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=m;i++)cin>>x>>y,add(y,x),cnt[x]++;
		for(i=1;i<=n;i++)if(!cnt[i])q.push(i);
		while(!q.empty())
		{
			int now=q.top();q.pop();
			ans[k--]=now;
			for(j=head[now];j;j=a[j].next)
				if(!(--cnt[a[j].go]))q.push(a[j].go);
		}
		if(k)cout<<"Impossible!";
		else for(i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
	}

	return 0;
}