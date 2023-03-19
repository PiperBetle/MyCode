#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
constexpr int N=5e5+1;
int n,m,deg[N][2],s[N];
bool vis[N];
std::basic_string<int>g[N];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){char c;cin>>c;s[i]=c-'A';}
	for(int u,v;m--;)cin>>u>>v,g[u]+=v,g[v]+=u,deg[u][s[v]]++,deg[v][s[u]]++;
	m=n;
	for(int i=1;i<=n;i++)if(!deg[i][0]||!deg[i][1])q.push(i),vis[i]=true,m--;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u])if(!--deg[v][s[u]]&&!vis[v])
			q.push(v),vis[v]=true,m--;
	}
	cout<<(m>0?"Yes":"No");
	return 0;
}