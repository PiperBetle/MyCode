#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
struct tree{int l,r;}a[1000007];
int ans=0;
void dfs(int now,int dis)
{
	ans=std::max(ans,dis);
	if(!now)return;
	dfs(a[now].l,dis+1);
	dfs(a[now].r,dis+1);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].l>>a[i].r;
	dfs(1,0);
	cout<<ans;
	
	return 0;
}