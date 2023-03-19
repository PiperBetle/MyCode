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
int n,q,a[N];
loli val;
int check(int l,int r,int x){
	loli sm=0,xr=0;
	for(int i=l;i<=l+x-1;i++)sm+=a[i],xr^=a[i];
	for(int i=l;i+x-1<=r;i++){
		if(sm-xr==val)return i;
		sm-=a[i];sm+=a[i+x];
		xr^=a[i];xr^=a[i+x];
	}
	return -1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>q;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int l,r;q--;){
			cin>>l>>r;
			loli sm=0,xr=0;
			for(int i=l;i<=r;i++)sm+=a[i],xr^=a[i];
			val=sm-xr;
			int L=1,R=r-l+1,mid;
			while(L<R){
				mid=(L+R)/2;
				if(check(l,r,mid)!=-1)R=mid;
				else L=mid+1;
			}
			int ans=check(l,r,R);
			cout<<ans<<' '<<ans+R-1<<'\n';
		}
	}
	return 0;
}