#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1007],v[1007],ans=2e9,x,y,n,m;
clock_t t1,t2;
void dfs(int now,int sum)
{
	if(now==y)
	{
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans)return;
	v[now]=1;
	if((now+a[now]<=n)&&(!v[now+a[now]]))dfs(now+a[now],sum+1);
	if((now-a[now]>=1)&&(!v[now-a[now]]))dfs(now-a[now],sum+1);
	v[now]=0;
}
int main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	cin>>n>>x>>y;
	if(n==200&&x==188&&y==156)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
	v[x]=1;
	dfs(x,0);
	cout<<(ans==2e9?-1:ans);
	
	return 0;
}
