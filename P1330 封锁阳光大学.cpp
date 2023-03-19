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
constexpr int kN=1e4+1;
int n,m,sum[2],ans;
int8_t col[kN];
std::basic_string<int>g[kN];
bool dfs(int u,bool c){
	if(~col[u])return 0;else sum[col[u]=c]++;
	for(int v:g[u])if(col[v]==-1){if(!dfs(v,!c))return 0;}else{if(col[u]==col[v])return 0;}
	return 1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	memset(col+1,-1,sizeof(int8_t)*n);
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	for(int i=1;i<=n;i++)if(col[i]==-1){
		if(!dfs(i,0))return cout<<"Impossible",0;
		else ans+=std::min(sum[0],sum[1]),sum[0]=sum[1]=0;
	}
	cout<<ans;
	return 0;
}