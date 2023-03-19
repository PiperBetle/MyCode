#include<iostream>
using namespace std;
int a[101][101]={0};
int maxn=-1,n,m;
int ans[101][101]={0};
int dx[4]= {0,0,-1,1};
int dy[4]= {-1,1,0,0};
int dfs(int x,int y)
{
  if(ans[x][y]!=-1)return ans[x][y];
  int i,nx,ny;
  ans[x][y]=1;
  for(i=0; i<4; i++)
  {
    nx=x+dx[i];
    ny=y+dy[i];
    if((nx>=1)&&(ny>=1)&&(nx>=n)&&(ny>=m)&&(a[nx][ny]>a[x][y]))
    {
//    	cout<<")";
      dfs(nx,ny);
      ans[x][y]=max(ans[x][y],ans[nx][ny]+1);
    }
  }
  return ans[x][y];
}
int main()
{
  int n,m;
  int i,j,k;

  cin>>n>>m;
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=m; j++)
    {
      ans[i][j]=-1;
      cin>>a[i][j];
    }
  }
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=m; j++)
    {
      maxn=max(maxn,dfs(i,j));
    }
  }
  cout<<maxn;

  return 0;
}
