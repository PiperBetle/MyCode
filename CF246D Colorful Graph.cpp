#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
int n,m,ans=0x3f3f3f3f,c[kN];
std::set<int>a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i],ans=std::min(ans,c[i]);
	for(int i=1,u,v;i<=m;i++){cin>>u>>v;if((u=c[u])!=(v=c[v]))a[u].insert(v),a[v].insert(u);}
	for(int i=1;i<=n;i++)if(siz(a[c[i]])>siz(a[ans]))ans=c[i];
	cout<<ans;
	return 0;
}