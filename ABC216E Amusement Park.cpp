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
constexpr int N=1e5+2;
int n,k,a[N],ans;
inline int calc(int x,int y){return (y*(y+1)-x*(x+1))/2;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n,std::greater<>());
	for(int i=1;i<=n;i++){
		int d=a[i]-a[i+1];
		if(d*i<=k){
			ans+=calc(a[i+1],a[i])*i;
			k-=d*i;
		}else{
			ans+=calc(a[i]-k/i,a[i])*i;
			ans+=(a[i]-k/i)*(k%i);
			break;
		}
	}
	cout<<ans;
	return 0;
}