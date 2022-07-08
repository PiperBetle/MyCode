#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr int kN=2e5+1;
int n,m;
long long a[kN],ans;
bool vis[kN];
std::basic_string<int>g[kN];
void dfs(int u){
	for(int v:g[u])if(!vis[v])vis[v]=true,dfs(v),ans+=a[v];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>m;g[i].resize(m);
		for(int &j:g[i])cin>>j;
	}
	vis[n]=true;dfs(n);
	cout<<ans+a[n];
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}