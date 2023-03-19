#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int ans=0;
void dfs(int begin,int last,int rest)
{
	if(last==1)
	{
		ans++;
		return;
	}
	for(int i=begin;i<=rest/last;i++)
		dfs(i,last-1,rest-i);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>k;
	dfs(1,k,n);
	cout<<ans;
	
	return 0;
}

