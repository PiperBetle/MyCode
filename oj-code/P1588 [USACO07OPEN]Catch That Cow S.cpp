#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>0?(a):-(a))
using namespace std;
int ans;
void dfs(int x,int y,int cnt)
{
	if(cnt>=ans)return;
	ans=min(ans,cnt+abs(x-y));
	if(x==y)
	{
		ans=min(ans,cnt);
		return;
	}
	if(x>y)dfs(x,y+1,cnt+1);
	else
		if(y%2)
		{
			dfs(x,y+1,cnt+1);
			dfs(x,y-1,cnt+1);
		}
		else dfs(x,y/2,cnt+1);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		if(n>m)
		{
			cout<<n-m<<endl;
			continue;
		}
		ans=m-n;
		dfs(n,m,0);
		cout<<ans<<endl;
	}
	
	return 0;
}
