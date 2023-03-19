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
constexpr int N=1e6+1;
bsc s;
int c[N][10];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=1;;i++){
		cauto &b=std::to_string(i);
		for(int j=i;--j;)if(s+=b,siz(s)>N)break;
	}
	s=' '+s;
	for(int i=1;i<N;i++){
		memcpy(c[i],c[i-1],sizeof(c[0]));
		c[i][s[i]-'0']++;
	}
	int T;cin>>T;for(int l,r;T--;){
		cin>>l>>r;
		loli sum=0;
		for(int i=0;i<=9;i++)sum+=i*(c[r][i]-c[l-1][i]);
		cout<<sum<<'\n';
	}
	return 0;
}