//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<vector>
#if __cplusplus>=202002L
#include<ranges>
using namespace std::views;
#endif
#define siz(x) int(std::size(x))
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x) {x;continue;}
#define break(x) {x;break;}
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
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::string;
#if __cplusplus>=201703L
using bscv=std::string_view;
#endif
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=2e5+1,inf=0x3f3f3f3f;
int n,m,fa[N],w[N],ans;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))fa[x]=y;}
struct{int x,y,w,id;}a[N];
bsi v;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;v.clear();
		for(int i=1;i<=n;i++)fa[i]=i,cin>>a[i].x>>a[i].y>>a[i].w,a[i].id=i;
		std::sort(a+1,a+1+n,[](cauto&p1,cauto&p2){return p1.x==p2.x?p1.y<p2.y:p1.x<p2.x;});
		for(int i=2;i<=n;i++)if(a[i-1].x==a[i].x&&a[i-1].y+m>=a[i].y)merge(a[i-1].id,a[i].id);
		std::sort(a+1,a+1+n,[](cauto&p1,cauto&p2){return p1.y==p2.y?p1.x<p2.x:p1.y<p2.y;});
		for(int i=2;i<=n;i++)if(a[i-1].y==a[i].y&&a[i-1].x+m>=a[i].x)merge(a[i-1].id,a[i].id);
		std::sort(a+1,a+1+n,[](cauto&p1,cauto&p2){return p1.id<p2.id;});
		memset(w+1,0x3f,sizeof(int)*n);
		for(int i=1;i<=n;i++)cmin(w[find(i)],a[i].w);
		for(int i=1;i<=n;i++)if(find(i)==i)v+=w[i];
		sort(all(v),std::greater<>());
		v+=-inf;for(ans=0;ans<siz(v);ans++)if(v[ans+1]<=ans)break;
		cout<<ans<<'\n';
	}
	return 0;
}