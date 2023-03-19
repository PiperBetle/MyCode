#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ext/pb_ds/priority_queue.hpp>
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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=101,NN=10001,M=2001;
int n,m,stt,end,f[N][NN],val=0x3f3f3f3f,ans=0;
bool vis[N][NN];
struct{int nxt,v,w1,w2;}e[M];int head[N],edge;
inline void add_edge(int u,int v,int w1,int w2){e[++edge]={head[u],v,w1,w2},head[u]=edge;}
struct node{int w1,w2,u;friend bool operator<(const node&x,const node &y){if(x.w1==y.w1)return x.w2>y.w2;else return x.w1>y.w1;}};
__gnu_pbds::priority_queue<node>q;
decltype(q)::point_iterator p[N][NN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>stt>>end;
	for(int i=1,u,v,w1,w2;i<=m;i++)cin>>u>>v>>w1>>w2,add_edge(u,v,w1,w2),add_edge(v,u,w1,w2);
	memset(f,0x3f,sizeof f);
	f[stt][0]=0;p[stt][0]=q.push({0,0,stt});
	while(!q.empty()){
		auto[w,t,u]=q.top();q.pop();
		if(vis[u][t])continue;else vis[u][t]=true;
		for(int i=head[u];i;i=e[i].nxt){
			auto[nxt,v,w1,w2]=e[i];
			if(t+e[i].w1>=NN)continue;
			if(f[v][t+e[i].w1]>f[u][t]+e[i].w2){
				f[v][t+e[i].w1]=f[u][t]+e[i].w2;
				if(p[v][t+e[i].w1]!=nullptr)q.modify(p[v][t+e[i].w1],{f[v][t+e[i].w1],t+e[i].w1,v});
				else p[v][t+e[i].w1]=q.push({f[v][t+e[i].w1],t+e[i].w1,v});
			}
		}
	}
	for(int i=0;i<NN;i++)if(f[end][i]<val)val=f[end][i],ans++;
	cout<<ans<<'\n';
	return 0;
}