#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int n,ans=5000000000000000000;
int p[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
void dfs(int m,int now,int end,int cnt)
{
	if(cnt>n||m<1||m>ans||now>16)
		return;
	if(cnt==n)
	{
		ans=m;
		return;
	}
	for(int i=1;i<=end;i++)
		dfs(m*=p[now],now+1,i,cnt*(i+1));
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	
	scanf("%lld",&n);
	dfs(1,1,64,1);
	printf("%lld\n",ans);
	
	return 0;
}