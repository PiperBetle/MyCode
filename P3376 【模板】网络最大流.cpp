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
constexpr int N=201,M=5001,inf=0x3f3f3f3f;
std::vector<pii>mem;
std::basic_string<int>g[N];
std::basic_string<int>::iterator cur[N];
inline void add(int u,int v,int w){
	g[u]+=siz(mem);mem.emplace_back(v,w);
	g[v]+=siz(mem);mem.emplace_back(u,0);
}
int n,m,s,t,dep[N];
loli ans;
inline bool bfs(){
	std::queue<int>q;
	memset(dep+1,0,sizeof(int)*n);
	dep[s]=1;q.push(s);cur[s]=g[s].begin();
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto it=g[u].begin();it!=g[u].end();++it){
			auto[v,w]=mem[*it];
			if(w&&!dep[v]){
				q.push(v);
				dep[v]=dep[u]+1;
				cur[v]=g[v].begin();
				if(v==t)return 1;
			}
		}
	}
	return 0;
}
inline int dinic(int u,int flow){
	if(u==t)return flow;
	int rest=flow,k;
	for(auto &it=cur[u];it!=g[u].end()&&rest;++it){
		auto[v,w]=mem[*it];
		if(w&&dep[v]==dep[u]+1){
			if(!(k=dinic(v,std::min(w,rest))))dep[v]=0;
			mem[*it].se-=k;mem[*it^1].se+=k;
			rest-=k;
		}
	}
	return flow-rest;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>s>>t;mem.reserve(m<<1);
	for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,add(u,v,w);
	for(int flow=0;bfs();)while((flow=dinic(s,inf)))ans+=flow;
	cout<<ans;
	return 0;
}