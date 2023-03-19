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
constexpr int N=5e5+1,MOD=998244353;
int n,f[N][2],ans;
inline int&mul1(int&x){return (x+=x)<MOD?x:x-=MOD;}
inline int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		memset(f+1,0,sizeof(f[0])*n);
		f[0][0]=1;f[0][1]=0;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			mul1(f[x+1][0]);mul1(f[x+1][1]);
			add1(f[x+1][0],f[x][0]);
			if(x)mul1(f[x-1][1]),add1(f[x-1][1],f[x-1][0]);
		}
		ans=f[0][1];
		for(int i=1;i<=n;i++)add1(ans,f[i][0]),add1(ans,f[i][1]);
		cout<<ans<<'\n';
	}
	return 0;
}