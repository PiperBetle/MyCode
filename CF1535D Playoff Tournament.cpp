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
constexpr int N=1<<19|1;
int n,m,s[N];
bsc a;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void build(int u,int l,int r){
	if(l==r){s[u]=1;return;}
	build(ls,l,mid);build(rs,mid+1,r);
	switch(a[u]){
		case '0':s[u]=s[rs];break;
		case '1':s[u]=s[ls];break;
		case '?':s[u]=s[ls]+s[rs];break;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>a>>m;n=1<<n;
	std::reverse(all(a));a=' '+a;
	build(1,1,n);
	for(int u;m--;){
		cin>>u;u=n-u;cin>>a[u];
		for(;u;u>>=1)switch(a[u]){
			case '0':s[u]=s[rs];break;
			case '1':s[u]=s[ls];break;
			case '?':s[u]=s[ls]+s[rs];break;
		}
		cout<<s[1]<<'\n';
	}
	return 0;
}