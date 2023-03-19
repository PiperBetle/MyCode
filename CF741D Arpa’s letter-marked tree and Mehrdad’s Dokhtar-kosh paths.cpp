#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr int N=5e5+1;
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
int n,fa[N],dep[N],mask[N],ans[N];
char c[N];
std::unordered_map<int,int>mp[N];
std::basic_string<int>g[N];
int merge(int u,int v){
	if(siz(mp[u])<siz(mp[v]))std::swap(mp[u],mp[v]);
	int res=0;
	for(auto[k,p]:mp[v]){
		if(mp[u].count(k))cmax(res,p+mp[u][k]);
		for(int j=0;j<22;j++)if(mp[u].count(k^(1<<j)))cmax(res,p+mp[u][k^(1<<j)]);
	}
	for(auto[k,p]:mp[v])cmax(mp[u][k],p);
	return res;
}
void dfs(int u){
	mp[u][mask[u]]=dep[u];
	for(int v:g[u]){
		dep[v]=dep[u]+1;
		mask[v]=mask[u]^(1<<(c[v]-'a'));
		dfs(v);
		cmax(ans[u],ans[v],merge(u,v)-dep[u]*2);
		mp[v].clear();
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=2;i<=n;i++)cin>>fa[i]>>c[i],g[fa[i]]+=i;
	dfs(1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}