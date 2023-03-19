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
constexpr int N=5e5+1,MOD=1e9+7,M=60;
int n,s[M];
loli a[N],ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;ans=0;
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int k=0;k<M;k++)s[k]+=a[i]>>k&1;
		}
		for(int i=1;i<=n;i++){
			loli s1=0,s2=0;
			for(int k=0;k<M;k++){
				loli v=(1ll<<k)%MOD;
				if(a[i]>>k&1)(s1+=s[k]*v)%=MOD,(s2+=n*v)%=MOD;
				else (s2+=s[k]*v)%=MOD;
			}
			(ans+=s1*s2)%=MOD;
		}
		cout<<ans<<'\n';
	}
	return 0;
}