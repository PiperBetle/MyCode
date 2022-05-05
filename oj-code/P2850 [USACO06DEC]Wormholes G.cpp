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
int head[1000007],l,cnt[1000007],dis[1000007],b[1000007];
void add(int u,int v,int t){l++;a[l].data=t;a[l].go=v;a[l].next=head[u];head[u]=l;}
std::queue<int>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int w,u,v,t;
	
	cin>>T;
	while(T--)
	{
		q.empty();
		memset(a,0,sizeof(edge)*1000007);
		memset(head,0,sizeof head);
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		memset(b,0,sizeof b);
		cin>>n>>m>>w;
		while(m--){cin>>u>>v>>t;add(u,v,t);add(v,u,t);}
		while(w--){cin>>u>>v>>t;add(u,v,-t);}
		int start=1;
		dis[start]=0;b[start]=1;
		q.push(start);cnt[start]=1;
		while(!q.empty())
		{
			int now=q.front();q.pop();
			b[now]=0;
			for(i=head[now];i;i=a[i].next)
				if(dis[a[i].go]>dis[now]+a[i].data)
				{
					dis[a[i].go]=dis[now]+a[i].data;
					cnt[a[i].go]=cnt[now]+1;
					if(cnt[a[i].go]>n)goto NO;
					if(!b[a[i].go]){q.push(a[i].go);b[a[i].go]=1;}
				}
		}
		cout<<"NO\n";continue;
		NO:cout<<"YES\n";
	}
	
	return 0;
}
