#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
std::vector<int>s[100007];
using std::cin;using std::cout;
int f[100007],in[100007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,u,v;
	for(i=1;i<=m;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u),in[u]++,in[v]++;
	return 0;
}