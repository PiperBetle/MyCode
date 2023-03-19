#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=200001;
int n,m,k,fa[N],cnt,i;
loli r;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct edge{int u,v,w;friend bool operator<(const edge &x,const edge &y){return x.w<y.w;}}e[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--)cout<<[]{
		cin>>n>>m>>k;r=cnt=0;
		for(i=1;i<=n;i++)fa[i]=i;
		for(i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
		std::sort(e+1,e+1+m);
		for(i=1;i<=m;i++){
			if(e[i].w>k)break;
			int u=find(e[i].u),v=find(e[i].v);
			if(u!=v)fa[u]=v,cnt++;
		}
		if(cnt==n-1){
			r=k-e[i-1].w;
			if(i<=m)cmin(r,0ll+e[i].w-k);
			return r;
		}
		for(;i<=m;i++){
			int u=find(e[i].u),v=find(e[i].v);
			if(u!=v){
				fa[u]=v;
				r+=e[i].w-k;
				if(++cnt==n-1)return r;
			}
		}
		return 0ll;
	}()<<'\n';
	return 0;
}