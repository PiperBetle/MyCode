#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define int loli
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+5;
int n,m,top,mx,ans,k,sum;
int dis[N];
int h[2*N],g[2*N],nxt[2*N],c[2*N],lim[2*N];
std::vector<int>lf;
void add(int x,int y,int a,int b){
	nxt[++top]=h[x];
	g[top]=y;
	c[top]=a;
	lim[top]=b;
	h[x]=top;
}
int dfs(int x,int fa,int val){
	bool vis=0;
	for(int i=h[x];i;i=nxt[i]){
		if(g[i]==fa) continue;
		dis[x]=max(dfs(g[i],x,val+c[i]),dis[x]);
		vis=1;
	}
	if(!vis) dis[x]=val;
	return dis[x];
}
void dfs1(int x,int fa,int val){
	bool vis=0;
	for(int i=h[x];i;i=nxt[i]){
		if(g[i]==fa) continue;
		vis=1;
		if(dis[g[i]]-val>k){
			int dta=c[i]-lim[i];
			if(dis[g[i]]-val-dta<=k){
				sum+=(dis[g[i]]-val)-k;
				continue;
			}
			sum+=dta;
			dfs1(g[i],x,val+dta);
		}
	}
	if(!vis&&dis[x]-val>k) sum=1e9;
	return ; 
}
bool check(int x){
	sum=0,k=x;
	dfs1(1,0,0);
	return sum<=m;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,x,y,a,b;i<n;i++){
		cin>>x>>y>>a>>b;
		add(x,y,a,b);
		add(y,x,a,b);
	}
	dfs(1,0,0);
	int l=0,r=1e18;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans;
}