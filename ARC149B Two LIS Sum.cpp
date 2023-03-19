#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=3e5+1,inf=0x3f3f3f3f;
int n,m,f[N];
pii a[N];
inline int calc1(){
	memset(f+1,0x3f,sizeof(int)*n);
	for(int i=1;i<=n;i++)
		*std::lower_bound(f+1,f+1+n,a[i].fi)=a[i].fi;
	return int(std::lower_bound(f+1,f+1+n,inf)-f)-1;
}
inline int calc2(){
	memset(f+1,0x3f,sizeof(int)*n);
	for(int i=1;i<=n;i++)
		*std::lower_bound(f+1,f+1+n,a[i].se)=a[i].se;
	return int(std::lower_bound(f+1,f+1+n,inf)-f)-1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].fi;
	for(int i=1;i<=n;i++)cin>>a[i].se;
	std::sort(a+1,a+1+n);
	m=calc1()+calc2();
	std::sort(a+1,a+1+n,[](const pii &x,const pii &y){return x.se<y.se;});
	cout<<std::max(m,calc1()+calc2());
	return 0;
}