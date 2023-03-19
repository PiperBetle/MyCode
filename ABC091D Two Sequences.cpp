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
constexpr int N=2e5+1;
int n,a[N],b[N],c[N],d[N],ans,*p1,*p2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int k=30;~k;k--){
		int p=1<<k,cnt=0;
		for(int i=1;i<=n;i++)c[i]=a[i]%(p*2);
		for(int i=1;i<=n;i++)d[i]=b[i]%(p*2);
		std::sort(c+1,c+1+n);
		std::sort(d+1,d+1+n);
		for(int i=1;i<=n;i++){
			p1=std::lower_bound(d+1,d+1+n,p-c[i]);
			p2=std::lower_bound(d+1,d+1+n,2*p-c[i]);
			cnt+=p2-p1+1;
			p1=std::lower_bound(d+1,d+1+n,3*p-c[i]);
			p2=std::lower_bound(d+1,d+1+n,4*p-c[i]);
			cnt+=p2-p1+1;
		}
		if(cnt&1)ans|=p;
	}
	cout<<ans;
	return 0;
}