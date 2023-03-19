//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<queue>
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
constexpr int N=2e5+1,inf=0x3f3f3f3f3f3f3f3f;
int n,m,k,a[N],deg[N],dis[N],ans=-1;
bsi g[N];
pii e[N];
std::queue<int>q;
bool check(int x){
	memset(deg+1,0,sizeof(int)*n);
	memset(dis+1,0,sizeof(int)*n);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=m;i++)if(max(a[e[i].fi],a[e[i].se])<=x)
		g[e[i].fi]+=e[i].se,deg[e[i].se]++;
	for(int i=1;i<=n;i++)if(!deg[i]&&a[i]<=x)dis[i]=1,q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dis[v]<dis[u]+1)dis[v]=dis[u]+1;
			if(!--deg[v])q.push(v);
		}
	}
	for(int i=1;i<=n;i++)if(dis[i]>=k||deg[i])return true;
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>e[i].fi>>e[i].se;
	int l=0,r=inf,mid;
	while(l<=r){
		if(check(mid=(l+r)/2))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}