#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1;
int n,m,a[kN],b[kN],c[kN];
std::basic_string<int>g[kN];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	for(int i=1;i<=n;i++)cin>>a[i],b[a[i]]=i;
	for(int i=1;i<=n;i++)std::sort(g[i].begin(),g[i].end(),[](int x,int y){return b[x]<b[y];});
	for(q.push(1);!q.empty();){
		int u=q.front();q.pop();
		c[++m]=u;
		for(int v:g[u])if(b[v]>b[u])q.push(v);
	}
	for(int i=1;i<=n;i++)if(a[i]!=c[i])return cout<<"No",0;
	cout<<"Yes";
	return 0;
}