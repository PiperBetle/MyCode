//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define int loli
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1000001;
int n,a[N],f[N][2];
bsi g[N];
void dfs(int u){
	int sum=0;
	for(int v:g[u])dfs(v),sum+=max(f[v][0],f[v][1]);
	f[u][0]=f[u][1]=sum;
	for(int v:g[u]){
		if(a[v]<=a[u])cmax(f[u][0],sum-max(f[v][0],f[v][1])+a[u]-a[v]+f[v][0]);
		if(a[v]>=a[u])cmax(f[u][1],sum-max(f[v][0],f[v][1])+a[v]-a[u]+f[v][1]);
	}
}
signed main(){
//	freopen("ex.in","r",stdin);
//	freopen("ex.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v;
	dfs(1);
	cout<<max(f[1][0],f[1][1]);
	return 0;
}