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
constexpr int N=1e5+1;
int n,a[N],l=1,r=2*N;
loli m,s[N],cnt,ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	while(l<r){
		int mid=(l+r+1)/2;cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			int p=int(std::lower_bound(a+1,a+1+n,mid-a[i])-a);
			cnt+=n-p+1;ans+=s[n]-s[p-1]+a[i]*(n-p+1);
		}
		if(cnt>=m)l=mid;else r=mid-1;
	}
	cout<<ans-(cnt-m)*l;
	return 0;
}