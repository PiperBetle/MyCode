#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=5e5+1;
int n,m,fat[kN],deg[kN];
std::basic_string<int>g[kN];
inline int find(int x){return x==fat[x]?x:fat[x]=find(fat[x]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=n;i++)cin>>u>>v,g[u]+=v,g[v]+=u,deg[u]++,deg[v]++;
	return 0;
}