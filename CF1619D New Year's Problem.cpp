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
constexpr int N=1e5+1,inf=0x3f3f3f3f;
int m,n,a[N];
inline int id(int x,int y){return (x-1)*n+y;}
bool check(int x){
	for(int j=1;j<=n;j++){
		bool f=1;
		for(int i=1;i<=m;i++)
			if(a[id(i,j)]>x){f=0;break;}
		if(f)return 0;
	}
	for(int i=1,k;i<=m;i++){
		k=0;
		for(int j=1;j<=n;j++)
			if((k+=a[id(i,j)]>x)==2)return 1;
	}
	return 0;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>m>>n;
		for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>a[id(i,j)];
		int l=1,r=inf,mid;
		while(l<r)
			if(check(mid=(l+r)/2))l=mid+1;
			else r=mid;
		cout<<l<<'\n';
	}
	return 0;
}