#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
using pli=std::pair<loli,int>;
constexpr int kN=2.5e5+2,inf=0x3f3f3f3f;
int n;
loli dis[kN];
bool vis[kN];
struct{int x,l,r,c;}a[kN];
std::basic_string<int>b,L[2*kN],R[2*kN];
std::vector<pii>g[kN];
std::set<pii>s;
std::priority_queue<pli>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;b.reserve(2*n);
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].l>>a[i].r>>a[i].c;
		b+=a[i].l,b+=a[i].r;
	}
	std::sort(b.begin(),b.end());
	b.erase(std::unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=n;i++){
		a[i].l=int(std::lower_bound(b.begin(),b.end(),a[i].l)-b.begin())+1;
		a[i].r=int(std::lower_bound(b.begin(),b.end(),a[i].r)-b.begin())+1;
		L[a[i].l]+=i;
		R[a[i].r]+=i;
	}
	s.emplace(0,0);s.emplace(inf,n+1);
	for(int i=1;i<=siz(b);i++){
		for(int j:R[i])s.erase({a[j].x,j});
		for(int j:R[i]){
			auto l=s.lower_bound({a[j].x,0});
			auto r=s.lower_bound({a[j].x+1,0});
			if(l==s.begin()||r==s.end())continue;
			int u=(--l)->second,v=r->second;
			if(u!=0||v!=n+1)g[u].emplace_back(v,a[u].c),g[v].emplace_back(u,a[v].c);
		}
		for(int j:L[i])s.emplace(a[j].x,j);
		for(int j:L[i]){
			auto l=s.lower_bound({a[j].x,0});
			auto r=s.lower_bound({a[j].x+1,0});
			if(l!=s.begin()){int u=(--l)->second,v=j;g[u].emplace_back(v,a[u].c),g[v].emplace_back(u,a[v].c);}
			if(r!=s.end()){int u=r->second,v=j;g[u].emplace_back(v,a[u].c),g[v].emplace_back(u,a[v].c);}
		}
	}
	memset(dis,0x3f,sizeof dis);
	dis[0]=0;q.emplace(0,0);
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;else vis[u]=true;
		for(auto[v,w]:g[u])if(dis[v]>dis[u]+w)dis[v]=dis[u]+w,q.emplace(-dis[v],v);
	}
	cout<<dis[n+1];
	return 0;
}