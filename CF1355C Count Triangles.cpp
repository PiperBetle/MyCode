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
	int a,b,c,d;
	loli s;
	signed main(){
	//	freopen(".in","r",stdin);
	//	freopen(".out","w",stdout);
		std::ios::sync_with_stdio(false);cin.tie(nullptr);
		cin>>a>>b>>c>>d;
		for(int i=max(c+1,a+b);i<=b+c;i++)
			s+=1ll*(min(d+1,i)-c)*(min(i-b,b)-max(i-c,a)+1);
		cout<<s;
		return 0;
	}