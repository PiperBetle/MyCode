//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
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
constexpr int N=1e6+1;
uloli pw[N],h[N];
uloli ask(int l,int r){return h[r]-h[l-1]*pw[r-l+1];}
int n,ans,f[N];
bsc s;
signed main(){
//	freopen("sydsdsj.in","r",stdin);
//	freopen("sydsdsj.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	pw[0]=1;for(int i=1;i<N;i++)pw[i]=pw[i-1]*233;
	int T;cin>>T;while(T--){
		cin>>s;n=siz(s);s=' '+s;ans=0;
		for(int i=1;i<=n;i++)h[i]=h[i-1]*233+s[i];
		int l=1,r=n;
		for(int i=1,j=n;i<=j;i++,j--){
			if(ask(l,i)!=ask(j,r))continue;
			l=i+1,r=j-1,ans+=1+(i!=j);
		}
		cout<<ans+(l<=r)<<'\n';
	}
	return 0;
}