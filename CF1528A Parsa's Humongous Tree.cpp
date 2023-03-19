#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define set_n(a,b,c) memset(a,b,sizeof*(a)*c)
#define cpy_n(a,b,c) memcpy(a,b,sizeof*(a)*c)
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+1;
int n,a[N][2];
loli f[N][3];
std::basic_string<int>g[N];
inline void dfs(int u,int fa){
	for(int v:g[u])if(v!=fa){
		dfs(v,u);
		f[u][0]+=std::max(f[v][0]+abs(a[u][0]-a[v][0]),f[v][1]+abs(a[u][0]-a[v][1]));
		f[u][1]+=std::max(f[v][0]+abs(a[u][1]-a[v][0]),f[v][1]+abs(a[u][1]-a[v][1]));
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
		for(int i=1;i<=n;i++)g[i].clear();
		set_n(f+1,0,n);
		for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
		dfs(1,0);
		cout<<std::max(f[1][0],f[1][1])<<'\n';
	}
	return 0;
}