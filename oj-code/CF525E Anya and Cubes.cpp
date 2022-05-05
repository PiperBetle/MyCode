#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#define int long long
using std::cin;using std::cout;
std::unordered_map<int,int>mp[30];
int fac[30],n,k,s,a[30],ans=0;
void dfs1(int now,int cnt,int sum){
	if(cnt>k||sum>s)return;
	if(now>(n>>1)){mp[cnt][sum]++;return;}
	dfs1(now+1,cnt,sum);
	dfs1(now+1,cnt,sum+a[now]);
	if(a[now]<=20)dfs1(now+1,cnt+1,sum+fac[a[now]]);
}
void dfs2(int now,int cnt,int sum){
	if(cnt>k||sum>s)return;
	if(now>n){for(int i=0;i<=k-cnt;i++)ans+=mp[i][s-sum];return;}
	dfs2(now+1,cnt,sum);
	dfs2(now+1,cnt,sum+a[now]);
	if(a[now]<=20)dfs2(now+1,cnt+1,sum+fac[a[now]]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i;
	cin>>n>>k>>s;
	for(i=1;i<=n;i++)cin>>a[i];
	for(fac[0]=i=1;i<=20;i++)fac[i]=fac[i-1]*i;
	dfs1(1,0,0);
	dfs2((n>>1)+1,0,0);
	cout<<ans;
	return 0;
}