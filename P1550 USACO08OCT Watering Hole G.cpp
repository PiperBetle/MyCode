#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
struct edge{int u,v,t;bool operator<(const edge&n){return t<n.t;}};
std::vector<edge>s;
int f[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k=0;
	int n,m,ans=0;
	int u,v,t;
	
	for(i=0;i<1000007;i++)f[i]=i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>t,s.emplace_back((edge){0,i,t});
	for(i=1;i<=n;i++)for(j=1;j<=n;j++){cin>>t;if(i!=j)s.emplace_back((edge){i,j,t});}
	std::sort(s.begin(),s.end());
	for(auto it:s)
	{
		int fx=find(it.u),fy=find(it.v);
		if(fx!=fy){ans+=it.t;k++;f[fx]=fy;}
		if(k==n)break;
	}
	cout<<ans;
	
	return 0;
}