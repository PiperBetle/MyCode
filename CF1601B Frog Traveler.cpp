//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<queue>
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
constexpr int N=3e5+1;
int n,fa[N],a[N],b[N],d[N];
pii p[N];
bsi ans;
std::queue<int>q;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){fa[find(x)]=find(y);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)fa[i]=i;
	memset(d,-1,sizeof(int)*n);
	q.push(n);d[n]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(u==0)break;
		for(int v=find(u)-1;u-v<=a[u];v=find(v)-1){
			merge(v+1,v);
			if(!~d[min(n,v+b[v])]){
				d[min(n,v+b[v])]=d[u]+1;
				p[min(n,v+b[v])]={u,v};
				q.push(min(n,v+b[v]));
			}
		}
	}
	cout<<d[0]<<'\n';
	if(!~d[0])return 0;
	for(int i=0;i!=n;i=p[i].fi)ans+=p[i].se;
	for(int i=siz(ans)-1;~i;i--)cout<<ans[i]<<' ';
	return 0;
}