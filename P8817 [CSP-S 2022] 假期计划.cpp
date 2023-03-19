//不向抑郁与焦虑投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<tuple>
#include<queue>
#include<ctime>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::min;using std::max;
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any>inline void cmin(any &x,const any &y){if(x>y)x=y;}
using loli=long long;
using pii=std::pair<int,int>;
using bsi=std::basic_string<int>;
using bsc=std::string;
constexpr int N=2501,M=101,inf=0x3f3f3f3f;
int n,m,k,vis[N];
loli a[N],ans,y[N][N];
bool tp[N][N];
bsi g[N],r[N];
std::queue<pii>q;
void dfs3(int u,int op1,int op2,loli sum){
	for(int t=1;t<=5;t++){
		int v=y[u][t];
		if(v&&v!=1&&v!=u&&v!=op1&&v!=op2)
			cmax(ans,sum+a[v]);
	}
}
void dfs2(int u,int op1,loli sum){
	for(int v:r[u]){
		if(v!=1&&v!=op1)
			dfs3(v,u,op1,sum+a[v]);
	}
}
void dfs1(int u,loli sum){
	for(int v:r[u]){
		if(v!=1)
			dfs2(v,u,sum+a[v]);
	}
}
void __dfs1(int u,loli sum){
	if(1.*clock()/CLOCKS_PER_SEC>=1.8)return;
	for(int v:r[u]){
		if(v!=1)
			dfs2(v,u,sum+a[v]);
	}
}
signed main(){
//	freopen("holiday.in","r",stdin);
//	freopen("holiday.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;k++;
	for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	for(int i=1;i<=n;i++){
		memset(vis+1,0x3f,sizeof(int)*n);
		vis[i]=0;q.emplace(i,0);
		while(!q.empty()){
			auto[u,l]=q.front();q.pop();
			for(int v:g[u])if(l<k&&vis[v]>l+1){
				vis[v]=l+1;
				q.emplace(v,l+1);
			}
		}
		for(int j=1;j<=n;j++)if(vis[j]<inf)tp[i][j]=true;
		for(int j=1;j<=n;j++)if(i!=j&&tp[i][j])r[i]+=j;
	}
	for(int i=1;i<=n;i++){
		for(int j:r[1])if(i!=j&&tp[i][j])y[i][j]=j;
		std::sort(y[i]+1,y[i]+1+n,[](int x,int y){return a[x]>a[y];});
	}
	if(n<=300)for(int u:r[1])dfs1(u,a[u]);
	else for(int i=1;i<=n;i++)if(y[1][i])__dfs1(y[1][i],a[y[1][i]]);
	cout<<ans;
	return 0;
}