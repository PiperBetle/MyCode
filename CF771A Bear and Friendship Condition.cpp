#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=150001;
int n,m,fat[kN],deg[kN],cnt[kN];
loli sum[kN];
inline int find(int x){return fat[x]==x?x:fat[x]=find(fat[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))fat[x]=y;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;for(int i=1;i<=n;i++)fat[i]=i;
	for(int u,v;m--;)cin>>u>>v,merge(u,v),deg[u]++,deg[v]++;
	for(int i=1;i<=n;i++)cnt[find(i)]++,sum[find(i)]+=deg[i];
	for(int i=1;i<=n;i++)if(i==find(i))if(1ll*cnt[i]*(cnt[i]-1)!=sum[i])return cout<<"NO",0;
	return cout<<"YES",0;
}