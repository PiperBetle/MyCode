#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<array>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using pil=std::pair<int,loli>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=50001;
int n,m;
loli sum[N];
bool vis[N];
std::vector<pil>g[N];
struct LineBase:std::array<loli,60>{
#define a (*this)
	auto &operator+=(loli x){
		for(int i=59;~i;i--){
			if(!(x>>i&1))continue;
			if(!a[i])return a[i]=x,*this;
			x^=a[i];
		}
		return *this;
	}
	auto max(){
		loli res=sum[n];
		for(int i=59;i>=0;i--)res=std::max(res,res^a[i]);
		return res;
	}
#undef a
}s;
void dfs(int u,int fa){
	vis[u]=true;
	for(auto[v,w]:g[u])if(v!=fa){
		if(vis[v])s+=sum[u]^sum[v]^w;
		else sum[v]=sum[u]^w,dfs(v,u);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	loli w;for(int u,v;m--;)cin>>u>>v>>w,g[u].emplace_back(v,w),g[v].emplace_back(u,w);
	dfs(1,0);cout<<s.max()<<'\n';
	return 0;
}