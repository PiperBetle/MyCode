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
constexpr int N=2e4+1,M=2e5+1;
int n,m,a[N],f[M],b[M],tr[M][2],tot=1;
void add(int x){
	int u=1;
	for(int i=1;i<=m;i++){
		int o=!(x%b[i]);
		if(!tr[u][o])tr[u][o]=++tot;
		u=tr[u][o];
	}
	f[u]+=x;
}
void dfs(int u,int d){
	if(!u)return;
	if(d<m)dfs(tr[u][0],d+1),dfs(tr[u][1],d+1);
	if(d&1)f[u]=min(f[tr[u][0]],f[tr[u][1]]);
	else f[u]=max(f[tr[u][0]],f[tr[u][1]]);
}
signed main(){
//	freopen("stefan.in","r",stdin);
//	freopen("stefan.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	if(m>=30)return cout<<0,0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=m;j++)cin>>b[j];
	for(int i=1;i<=n;i++)add(a[i]);
	dfs(1,1);cout<<f[1];
	return 0;
}