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
constexpr bool ying=false,yang=true;
constexpr int N=2e5+1;
int n,a[N];
bool check(int x){
#define ls(p1,p2) (a[p1]<=x&&a[p2]<=x)
#define rs(p1,p2) (a[p1]>x&&a[p2]>x)
	for(int i=0;i<n-1;i++){
		if(ls(n-i-1,n-i)||ls(n+i,n+i+1))return ying;
		if(rs(n-i-1,n-i)||rs(n+i,n+i+1))return yang;
	}
	return a[1]>x;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<2*n;i++)cin>>a[i];
	int l=1,r=2*n-1,mid;
	while(l<r)if(check(mid=(l+r)/2))l=mid+1;else r=mid;
	cout<<r;
	return 0;
}