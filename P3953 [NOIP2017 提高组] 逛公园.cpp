#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<queue>
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
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+1,M=51;
std::vector<pii>g1[N],g2[N];
int n,m,k,MOD,ans,f[N][M],dis[N];
bool vis[N][M],djv[N];
std::priority_queue<pii,std::vector<pii>,std::greater<pii>>q;
inline int add0(int _x,int _y){return (_x+=_y)<MOD?_x:_x-MOD;}
template<typename...args>inline int add0(int _x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-MOD;}
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
template<typename...args>inline int&add1(int&_x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-=MOD;}
inline int add0(inlsi _x){int _y=0;for(int _i:_x)add1(_y,_i);return _y;}
inline int&add1(int&_x,inlsi _y){return add1(_x,add0(_y));}
inline int sub0(int _x,int _y){return (_x-=_y)<0?_x+MOD:_x;}
template<typename...args>inline int sub0(int _x,args..._y){return (_x-=add0(_y...))<0?_x+MOD:_x;}
inline int&sub1(int&_x,int _y){return (_x-=_y)<0?_x+=MOD:_x;}
template<typename...args>inline int&sub1(int&_x,args..._y){return (_x-=add0(_y...))<0?_x+=MOD:_x;}
inline int sub0(inlsi _x,inlsi _y){return sub0(add0(_x),add0(_y));}
inline int&sub1(int&_x,inlsi _y){return sub1(_x,add0(_y));}
inline int mul0(int _x,int _y){return int(1ll*_x*_y%MOD);}
template<typename...args>inline int mul0(int _x,args..._y){return int(1ll*_x*mul0(_y...)%MOD);}
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%MOD);}
template<typename...args>inline int&mul1(int&_x,args..._y){return _x=int(1ll*_x*mul0(_y...)%MOD);}
inline int mul0(inlsi _x){int _y=1;for(int _i:_x)mul1(_y,_i);return _y;}
inline int&mul1(int&_x,inlsi _y){return mul1(_x,mul0(_y));}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,mul1(_x,_x))if(_y&1)mul1(_t,_x);return _t;}
inline int _inv(int _x){return qp(_x,MOD-2);}
inline int div0(int _x,int _y){return mul0(_x,_inv(_y));}
template<typename...args>inline int div0(int _x,args..._y){return mul0(_x,_inv(mul0(_y...)));}
inline int&div1(int&_x,int _y){return _x=mul0(_x,_inv(_y));}
template<typename...args>inline int&div1(int&_x,args..._y){return _x=mul0(_x,_inv(mul0(_y...)));}
inline int div0(inlsi _x,inlsi _y){return div0(mul0(_x),mul0(_y));}
inline int&div1(int&_x,inlsi _y){return div1(_x,mul0(_y));}
int dfs(int u,int l){
	if(l<0||l>k)return 0;
	if(vis[u][l])return vis[u][l]=false,-1;
	if(~f[u][l])return f[u][l];else vis[u][l]=true;
	int res=0;
	for(auto[v,w]:g2[u])if(int t=dfs(v,dis[u]-dis[v]-w+l);!~t)return vis[u][l]=0,-1;else add1(res,t);
	vis[u][l]=false;
	return f[u][l]=(res+=u==1&&!l);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m>>k>>MOD;ans=0;
		for(int i=1;i<=n;i++)g1[i].clear(),g2[i].clear();
		for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,g1[u].emplace_back(v,w),g2[v].emplace_back(u,w);
		memset(f,-1,sizeof f);
		memset(dis+1,0x3f,sizeof(int)*n);
		memset(djv+1,0,sizeof(bool)*n);
		q.emplace(0,1);dis[1]=0;
		while(!q.empty()){
			int u=q.top().se;q.pop();
			if(djv[u])continue;else djv[u]=true;
			for(auto[v,w]:g1[u])if(dis[v]>dis[u]+w)
				if(dis[v]=dis[u]+w,!djv[v])q.emplace(dis[v],v);
		}
		for(int i=0;i<=k;i++)if(int t=dfs(n,i);!~t)goto next;else add1(ans,t);
		cout<<ans<<'\n';
		continue;next:
		cout<<"-1\n";
	}
	return 0;
}