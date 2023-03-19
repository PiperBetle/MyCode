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
constexpr int N=4e5+1,M=std::__lg(N)+1;
int n,m,g[M][N],ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;m=ans=0;
		for(int i=1;i<=n;i++)cin>>g[0][i],m=std::__gcd(g[0][i],m);
		for(int i=1;i<=n;i++)g[0][i+n]=(g[0][i]/=m);
		for(int i=1;(1<<i)<=2*n;i++)for(int j=1;j+(1<<i)-1<=2*n;j++)
			g[i][j]=std::__gcd(g[i-1][j],g[i-1][j+(1<<(i-1))]);
		auto ask=[](int l,int r){int t=std::__lg(r-l+1);return std::__gcd(g[t][l],g[t][r-(1<<t)+1]);};
		for(int i=1;i<=n;i++){
			int p=i;
			for(int j=1<<std::__lg(n);j;j>>=1)
				if(p+j<i+n&&ask(i,p+j)>1)p+=j;
			if(g[0][p]!=1)p++;cmax(ans,p-i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}