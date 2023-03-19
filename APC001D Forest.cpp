//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
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
constexpr int N=1e5+1;
int n,m,tot,a[N],fa[N],cnt[N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
loli ans;
bsi g[N],b[N],r;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],fa[i]=i;
	for(int i=1,u,v;i<=m;i++)if(cin>>u>>v,(u=find(u+1))!=(v=find(v+1)))fa[u]=v;
	for(int i=1;i<=n;i++){
		if(!cnt[find(i)])cnt[find(i)]=++tot;
		b[cnt[find(i)]]+=a[i];
	}
	if(tot==1)return cout<<0,0;
	for(int i=1;i<=tot;i++){
		sort(all(b[i]));ans+=b[i].front();
		for(int j=1;j<siz(b[i]);j++)r+=b[i][j];
	}
	sort(all(r));
	if(siz(r)<tot-2)return cout<<"Impossible",0;
	for(int i=0;i<tot-2;i++)ans+=r[i];
	cout<<ans;
	return 0;
}