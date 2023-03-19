//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define int loli
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
constexpr int N=2e5+2,inf=0x3f3f3f3f;
int n,p,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>a[n+1];p=1;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++)if(a[i]-a[i-1]<a[p]-a[p-1])p=i;
		auto calc=[](int x){
			int mn=inf,mx=-inf,j=0;
			for(int i=1;i<=n;i++)if(i!=x)
				cmin(mn,a[i]-a[j]-1),cmax(mx,a[i]-a[j]-1),j=i;
			return min(mn,max((mx-1)/2,a[n+1]-a[j]-1));
		};
		int ans=calc(p);
		if(p!=1)cmax(ans,calc(p-1));
		cout<<ans<<'\n';
	}
	return 0;
}