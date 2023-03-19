#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<random>
#define int unsigned long long
using std::cin;using std::cout;
struct edge{int u,v;};
std::vector<edge>e;
int h[1000007],s[1000007];
signed main()
{
	// freopen("function.in","r",stdin);
	// freopen("function.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,cnt=1;
	int u,v,ans=0;
	std::mt19937 rand(std::random_device{}());
	
	for(i=0;i<1000007;i++)h[i]=h[i-1]+rand();
	cin>>n>>m;
	while(m--)cin>>u>>v,e.emplace_back((edge){u,v}),s[u]+=h[v],s[v]+=h[u];
	for(auto it:e)if(s[it.u]+h[it.u]==s[it.v]+h[it.v])ans++;
	std::sort(s+1,s+1+n);
	for(i=2;i<=n;i++)
		if(s[i]==s[i-1])cnt++;
		else ans+=(cnt*(cnt-1))>>1,cnt=1;
	ans+=(cnt*(cnt-1))>>1;
	cout<<ans;
	
	return 0;
}
