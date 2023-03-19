#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<numeric>
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
int n,m,p1=1,p2=inf,l[N],p[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;for(int i=1;i<=m;i++)cin>>l[i];
	if(std::accumulate(l+1,l+1+m,0ll)<n)return cout<<"-1",0;
	for(int i=1;i<=m;i++)if(cmin(p2,p[i]=n-i+2-l[i]),p2<=0)return cout<<"-1",0;
	for(int i=m;p1<=p2;i--)p[i]=p1,p1+=l[i];
	for(int i=1;i<=m;i++)cout<<p[i]<<' ';
	return 0;
}