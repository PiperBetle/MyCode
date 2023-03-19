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
constexpr int N=1e6+1;
int n,fa[N],sz[N],a[N];
loli sum1,sum2;
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))fa[x]=y,sz[y]+=sz[x];}
struct edge{
	int u,v;pii w;
	friend bool operator<(const edge &x,const edge &y){return x.w.fi>y.w.fi;}
	friend bool operator>(const edge &x,const edge &y){return x.w.se<y.w.se;}
}e[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],fa[i]=i,sz[i]=1;
	for(int i=1;i<n;i++)cin>>e[i].u>>e[i].v,e[i].w=std::minmax(a[e[i].u],a[e[i].v]);
	std::sort(e+1,e+n);
	for(int i=1;i<n;i++)sum1+=1ll*sz[find(e[i].u)]*sz[find(e[i].v)]*e[i].w.fi,merge(e[i].u,e[i].v);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	std::sort(e+1,e+n,std::greater<>());
	for(int i=1;i<n;i++)sum2+=1ll*sz[find(e[i].u)]*sz[find(e[i].v)]*e[i].w.se,merge(e[i].u,e[i].v);
	cout<<sum2-sum1;
	return 0;
}