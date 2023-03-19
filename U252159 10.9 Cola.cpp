#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<set>
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
constexpr int M=1001;
int n,m,k,a[M],b[M],c[M],d[M];
bsc s;
bsi r[M];
std::set<pii>o;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k>>s;s=' '+s;
	for(int i=1;i<=m;i++)cin>>a[i],o.emplace(k,i),r[a[i]]+=i,c[i]=k;
	for(int i=1;i<=n;i++){
		auto x=(s[i]=='R'?*o.rbegin():*o.begin());
		o.erase(x);x.fi--;c[b[i]=x.se]--;
		if(x.fi)o.insert(x);
	}
	for(int i=1;i<=m;i++)d[i]=r[c[i]].back(),r[c[i]].pop_back();
	for(int i=1;i<=n;i++)cout<<d[b[i]]<<' ';
	return 0;
}