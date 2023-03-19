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
constexpr int N=2e5+2;
int n,m,a[N],f[N],mx[N],ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1,x;i<=n;i++)cin>>x;
		std::sort(a+1,a+1+n);
		f[n+1]=mx[n+1]=0;
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&a[j+1]-a[i]<=m)j++;
			f[i]=j-i+1;
		}
		for(int i=n;i>=1;i--)mx[i]=max(mx[i+1],f[i]);
		for(int i=1;i<=n;i++)cmax(ans,f[i]+mx[i+f[i]]),assert(i+f[i]);
		cout<<ans<<'\n';
	}
	return 0;
}