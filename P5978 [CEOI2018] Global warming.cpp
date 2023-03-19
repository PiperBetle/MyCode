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
constexpr int N=2e5+1;
int n,m,a[N],ans,f[N];
bsi b;
signed main(){
//	freopen("nablqd.in","r",stdin);
//	freopen("nablqd.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		auto p=lower_bound(all(b),a[i]);
		if(p==b.end())b+=a[i],p=--b.end();else *p=a[i];
		cmax(ans,f[i]=p-b.begin()+1);
	}
	b.clear();
	for(int i=n;i>=1;i--){
		int j=lower_bound(all(b),-a[i]+m)-b.begin();
		auto p=lower_bound(all(b),-a[i]);
		if(p==b.end())b+=-a[i];else *p=-a[i];
		cmax(ans,f[i]+j);
	}
	cout<<ans;
	return 0;
}