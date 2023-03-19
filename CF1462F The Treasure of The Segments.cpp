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
constexpr int N=2e5+1;
bsi b;
pii a[N];
int n,m;
struct{
	int d[N<<1];
	void add(int x){for(;x<siz(b);x+=x&-x)d[x]++;}
	void del(int x){for(;x<siz(b);x+=x&-x)d[x]--;}
	int ask(int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
	int ask(int x,int y){return ask(y)-ask(x-1);}
	void clear(){memset(d,0,sizeof(int)*siz(b));}
}c1,c2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;b=m=0;
		for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se,(b+=a[i].fi)+=a[i].se;
		sort(all(b));b.erase(unique(all(b)),b.end());
		for(int i=1;i<=n;i++)
			a[i].fi=int(lower_bound(all(b),a[i].fi)-b.begin()),
			a[i].se=int(lower_bound(all(b),a[i].se)-b.begin()),
			c2.add(a[i].fi);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
			cmax(m,c1.ask(a[i].fi,siz(b)-1)+c2.ask(a[i].fi,a[i].se)),
			c1.add(a[i].se),c2.del(a[i].fi);
		c1.clear();
		cout<<n-m<<'\n';
	}
	return 0;
}