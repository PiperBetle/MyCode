#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
char c[1007][1007];
bool b[1007][1007];
struct point{int x,y,step;}begin,end,go;
std::queue<point>q;
std::vector<point>w[26];
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	cin>>n>>m;
	begin.step=end.step=0;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	{
		cin>>c[i][j];
		if(c[i][j]=='@')begin.x=i,begin.y=j;
		else if(c[i][j]=='=')end.x=i,end.y=j;
		else if(isupper(c[i][j]))w[c[i][j]-'A'].emplace_back((point){i,j,0});
	}
	for(i=0;i<26;i++)if(w[i].size()==1)c[w[i][0].x][w[i][0].y]='.',w[i].pop_back();
	memset(b,0,sizeof b);while(!q.empty())q.pop();
	q.push(begin);
	do
	{
		point now=q.front();q.pop();
		for(i=0;i<4;i++)
		{
			go.x=now.x+dx[i];
			go.y=now.y+dy[i];
			if(go.x>=1&&go.x<=n&&go.y>=1&&go.y<=m&&!b[go.x][go.y]&&c[go.x][go.y]!='#')
			{
				go.step=now.step+1;
				if(go.x==end.x&&go.y==end.y)return cout<<go.step<<'\n',0;
				b[go.x][go.y]=1;int tt=c[go.x][go.y]-'A';
				if(isupper(tt+'A'))
					if(go.x==w[tt][0].x&&go.y==w[tt][0].y)go.x=w[tt][1].x,go.y=w[tt][1].y;
					else go.x=w[tt][0].x,go.y=w[tt][0].y;
				q.push(go);
			}
		}
	}while(!q.empty());
	
	return 0;
}