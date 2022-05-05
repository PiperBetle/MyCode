#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define int long long
using namespace std;
struct line
{
	int x,y;
};
char map[1007][1007];
int ans[1007][1007];
int n,m;
char mod[5]={'\\','/','\\','/'};
int dx1[]={1,-1,-1,1},dy1[]={1,1,-1,-1},dx2[]={0,-1,-1,0},dy2[]={0,0,-1,-1};
deque<line> q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>map[i][j];
	if((n+m)&1)
		puts("NO SOLUTION");
	else
	{
		memset(ans,0x3f,sizeof ans);
		q.push_back({1,1});
		ans[1][1]=0;
		while(!q.empty())
		{
			line tt=q.front();
			q.pop_front();
			for(i=0;i<4;i++)
			{
				line nt1,nt2;
				nt1.x=tt.x+dx1[i];
				nt1.y=tt.y+dy1[i];
				nt2.x=tt.x+dx2[i];
				nt2.y=tt.y+dy2[i];
				if(nt1.x>=1&&nt1.y>=1&&nt1.x<=n+1&&nt1.y<=m+1)
					if(mod[i]!=map[nt2.x][nt2.y])
					{
						int t=ans[tt.x][tt.y]+1;
						if(t<ans[nt1.x][nt1.y])
						{
							q.push_back(nt1);
							ans[nt1.x][nt1.y]=t;
						}
					}
					else
					{
						int t=ans[tt.x][tt.y];
						if(t<ans[nt1.x][nt1.y])
						{
							q.push_front(nt1);
							ans[nt1.x][nt1.y]=t;
						}
					}
			}
		}
		cout<<ans[n+1][m+1]<<'\n';
	}
	
	return 0;
}