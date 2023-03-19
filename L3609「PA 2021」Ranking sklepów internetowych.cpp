#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ext/pb_ds/assoc_container.hpp>
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
namespace pbds=__gnu_pbds;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e6+1;
int n,a[N],b[N];
loli ans;
signed main(){
//	freopen("guitar.in","r",stdin);
//	freopen("guitar.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;cout<<n*2+1<<' ';
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[a[i]]=i;
	for(int i=1,j=0,l=n,r=1;i<=n;i++){
		for(;j*2<=i;j++)cmin(l,b[n-j]),cmax(r,b[n-j]);
		if(r-l+1<=i){
			int L=max(r-i+1,1),R=min(l,n-i+1);
			if(L<=R)ans+=R-L+1;
		}
	}
	cout<<ans;
	return 0;
}