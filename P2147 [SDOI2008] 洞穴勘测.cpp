#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<random>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
int n,m;
std::mt19937 rng(std::random_device{}());
std::string s;
int f[kN];
void sroot(int x){for(int c=0,fa=f[x];x;fa=f[x])f[x]=c,c=x,x=fa;}
signed main(){
//	freopen("TheWorld.in","r",stdin);
//	freopen("TheWorld.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int u,v;m--;){
		cin>>s>>u>>v;
		if(rng()&1)std::swap(u,v);
		sroot(u);
		if(s.front()=='C')f[u]=v;
		else if(s.front()=='D')f[v]=0;
		else {for(;v!=u&&v;v=f[v]);cout<<(u==v?"Yes\n":"No\n");}
	}
	return 0;
}