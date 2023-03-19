#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using std::cin;using std::cout;
int a[17][17],b[17][17];
bool _a[17][17],_b[17][17],_c[17][17];
inline void dfs(int now)
{
	int x=(now-1)/9+1,y=now%9;if(y==0)y=9;
	if(b[x][y]!=0){dfs(now+1);return;}
	if(now==82){
		for(int i=1;i<=9;i++,cout<<'\n')for(int j=1;j<=9;j++)cout<<b[i][j]<<' ';
		cout<<'\n';
		if(now==82)exit(0);
	}
	for(int i=1;i<=9;i++){
		int t=(x-1)/3*3+(y-1)/3+1;
		if(_a[x][i]||_b[y][i]||_c[t][i])continue;
		b[x][y]=i;
		_a[x][i]=1;_b[y][i]=1;_c[t][i]=1;
		dfs(now+1);
		_a[x][i]=0;_b[y][i]=0;_c[t][i]=0;
		b[x][y]=0;
	}
}
signed main()
{
	// freopen("sudoku.in","r",stdin);
	// freopen("sudoku.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	for(i=1;i<=9;i++)for(j=1;j<=9;j++)
	{
		cin>>b[i][j];
		if(b[i][j])
		{
			_a[i][b[i][j]]=1;
			_b[j][b[i][j]]=1;
			int t=(i-1)/3*3+(j-1)/3+1;
			_c[t][b[i][j]]=1;
		}
	}
	dfs(1);
	
	return 0;
}