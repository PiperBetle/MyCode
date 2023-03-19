#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
constexpr int N=5e5+1;
int n,ans,p[N],deg[N];
bool vis[N];
void dfs(int u,bool c){
	if(vis[u])return;else vis[u]=true;
	ans+=c;
	if(!--deg[p[u]]||c)dfs(p[u],!c);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i],deg[p[i]]++;
	for(int i=1;i<=n;i++)if(!deg[i])dfs(i,true);
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,false);
	cout<<ans;
	return 0;
}