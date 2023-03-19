#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
int n,m,k,fa[kN],sz[kN],cnt[kN];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))fa[y]=x,sz[x]+=sz[y];}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int x,y;m--;)cin>>x>>y,cnt[x]++,cnt[y]++,merge(x,y);
	for(int x,y;k--;)if(cin>>x>>y,find(x)==find(y))cnt[x]++,cnt[y]++;
	for(int i=1;i<=n;i++)cout<<sz[find(i)]-cnt[i]-1<<' ';
	return 0;
}