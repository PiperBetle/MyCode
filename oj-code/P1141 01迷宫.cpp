#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
int n,m,f[1000007],cnt[1000007];
char a[1007][1007];
int dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1};
inline int fix(int _x,int _y)
{
	return (_x-1)*n+_y;
}
int find(int _x){return _x==f[_x]?_x:f[_x]=find(f[_x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int x,y;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	for(i=0;i<1000007;i++)
	{
		cnt[i]=1;
		f[i]=i;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=0;k<4;k++)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];
				if((nx>=1)&&(nx<=n)&&(ny>=1)&&(ny<=n)&&(a[i][j]!=a[nx][ny]))
				{
					int fx=find(fix(i,j));
					int fy=find(fix(nx,ny));
					if(fx!=fy)
					{
						f[fy]=fx;
						cnt[fx]+=cnt[fy];
						cnt[fy]=0;
					}
				}
			}
	while(m--)
	{
		cin>>x>>y;
		cout<<cnt[find(fix(x,y))]<<'\n';
	}
	
	return 0;
}
