#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<list>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
std::basic_string<int>g[kN];
int n,m;
bool vis[kN],cov[kN];
std::list<int>a;
std::queue<int>q;
std::basic_string<int>ans;
decltype(a)::iterator p[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	for(int i=1;i<=n;i++)a.push_back(i),p[i]=--a.end();
	for(int i=1;i<=n;i++)if(!vis[i]){
		ans+=1;vis[i]=true;q.push(i);a.erase(p[i]);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v:g[u])if(!vis[v])cov[v]=true;
			for(auto v=a.begin();v!=a.end();)if(!cov[*v]){
				ans.back()++;vis[*v]=true;q.push(*v);v=a.erase(v);
			}else cov[*v]=false,v++;
		}
	}
	cout<<siz(ans)<<'\n';
	std::sort(all(ans));
	for(int i:ans)cout<<i<<' ';
	return 0;
}