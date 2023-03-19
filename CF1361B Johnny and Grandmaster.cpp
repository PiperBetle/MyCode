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
constexpr int N=1e6+1;
int n,m,a[N],s1,s2;
template<int P>struct MOD{
	static constexpr int&mul1(int&x,int y){return x=int(1ll*x*y%P);}
	static constexpr int qp(int x,int y=P-2){int z=1;for(;y;y/=2,mul1(x,x)) if(y&1)z=mul1(z,x);return z;}
	static constexpr int&sub1(int&x,int y){return (x-=y)<0?x+=P:x;}
};
using P1=MOD<1000000007>;
using P2=MOD<19260817>;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(m==1){cout<<(n&1)<<'\n';continue;}
		std::sort(a+1,a+1+n);s1=s2=0;
		for(int i=n;i>=1;i--)
			if(!s1&&!s2)s1=P1::qp(m,a[i]),s2=P2::qp(m,a[i]);
			else P1::sub1(s1,P1::qp(m,a[i])),P2::sub1(s2,P2::qp(m,a[i]));
		cout<<s1<<'\n';
	}
	return 0;
}