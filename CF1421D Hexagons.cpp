#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define int loli
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
int c1,c2,c3,c4,c5,c6,x,y;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>x>>y>>c1>>c2>>c3>>c4>>c5>>c6;
		cmin(c1,c6+c2);cmin(c2,c1+c3);cmin(c3,c2+c4);
		cmin(c4,c3+c5);cmin(c5,c4+c6);cmin(c6,c5+c1);
		if(x>=0&&y>=0){
			if(x>y)cout<<y*c1+(x-y)*c6<<'\n';
			else cout<<x*c1+(y-x)*c2<<'\n';
		}else if(x<=0&&y<=0){
			if(x<y)cout<<-y*c4-(x-y)*c3<<'\n';
			else cout<<-x*c4-(y-x)*c5<<'\n';
		}else if(x>=0&&y<=0){
			cout<<x*c6-y*c5<<'\n';
		}else if(x<=0&&y>=0){
			cout<<-x*c3+y*c2<<'\n';
		}
	}
	return 0;
}