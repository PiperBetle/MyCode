#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr int kN=1e5+1;
std::basic_string<int>g[kN];
using pii=std::pair<int,int>;
bool vis[kN][3];
int n,m,s,t;
signed main(){
//	freopen("checkers.in","r",stdin);
//	freopen("checkers.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v;
	cin>>s>>t;vis[s][0]=true;
	std::queue<pii>q({{s,0}});
	while(!q.empty()){
		auto[u,x]=q.front();x++;q.pop();
		for(int v:g[u])if(!vis[v][x%3]){
			if(v==t&&x%3==0)return cout<<x/3,0;
			vis[v][x%3]=true;
			q.emplace(v,x);
		}
	}
	cout<<"-1";
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}