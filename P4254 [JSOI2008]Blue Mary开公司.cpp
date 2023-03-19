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
using pdd=std::pair<double,double>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=50001;
bsc str;
pdd a[N<<2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void upd(int u,int l,int r,double x,double k){
	if(l==r){cmax(a[u].se,x+k*(r-1));a[u].fi=a[u].se;return;}
	if(k>0&&a[u].fi>x+k*(r-1))return;
	if(k<0&&a[u].fi>x+k*(l-1))return;
	upd(ls,l,mid,x,k);upd(rs,mid+1,r,x,k);
	a[u].fi=min(a[ls].fi,a[rs].fi);
	a[u].se=max(a[ls].se,a[rs].se);
}
double ask(int u,int l,int r,int x){
	if(l==r)return a[u].se;
	return x<=mid?ask(ls,l,mid,x):ask(rs,mid+1,r,x);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>str;
		if(str.front()=='P'){
			double s,p;cin>>s>>p;
			upd(1,1,N-1,s,p);
		}else{
			int d;cin>>d;
			cout<<int(ask(1,1,N-1,d)/100)<<'\n';
		}
	}
	return 0;
}