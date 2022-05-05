#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int b[2007][2007];
char c[2007][2007];
struct point{int x,y;}begin,go;
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
inline int hash(point n){return 10000*n.x+n.y;}
std::queue<point>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)for(j=0;j<m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='S')begin.x=i,begin.y=j;
		}
		memset(b,0,sizeof b);while(!q.empty())q.pop();
		begin.x+=10000*n;begin.y+=10000*m;
		b[begin.x%n][begin.y%m]=hash(begin);
		q.push(begin);
		do
		{
			point now=q.front();q.pop();
			for(i=0;i<4;i++)
			{
				go.x=now.x+dx[i];
				go.y=now.y+dy[i];
				if(c[go.x%n][go.y%m]=='#')continue;
				if(b[go.x%n][go.y%m]==0)b[go.x%n][go.y%m]=hash(go);
				else if(b[go.x%n][go.y%m]!=hash(go))goto next;
				else continue;
				q.push(go);
			}

		}while(!q.empty());
		cout<<"No\n";continue;next:cout<<"Yes\n";
	}
	
	return 0;
}