#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
long long a[21][21][21],n;
long long dfs(long long x,long long y,long long z)
{
	if((x>n)||(y>n)||(z<0))return 0;
	if(a[x][y][z]!=-1)return a[x][y][z];
	if((x==n)&&(y==n))return 1;
	a[x][y][z]=dfs(x+1,y,z+1)+dfs(x,y+1,z-1);
	return a[x][y][z];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	cin>>n;
	for(i=0;i<=20;i++)for(j=0;j<=20;j++)for(k=0;k<=20;k++)a[i][j][k]=-1;
	cout<<dfs(0,0,0);
	
    return 0;
}
