#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
std::vector<int>s;
using std::cin;using std::cout;
int a[57],n,m,k,ans=0;
void dfs1(int now,int sum){
	if(now==k){s.emplace_back(sum);return;}
	if(sum+a[now]<=m)dfs1(now+1,sum+a[now]);
	dfs1(now+1,sum);
}
void dfs2(int now,int sum){
	if(now>n){
		auto p=std::upper_bound(s.begin(),s.end(),m-sum)-1;
		ans=std::max(ans,sum+*p);return;
	}
	if(sum+a[now]<=m)dfs2(now+1,sum+a[now]);
	dfs2(now+1,sum);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>m>>n;k=n>>1;if(n>=40)k+=2;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1)return cout<<(a[1]<=m?a[1]:0),0;
	std::sort(a+1,a+1+n,std::greater<int>());
	dfs1(1,0);
	std::sort(s.begin(),s.end());
	s.erase(std::unique(s.begin(),s.end()),s.end());
	dfs2(k,0);
	cout<<ans;
	return 0;
}