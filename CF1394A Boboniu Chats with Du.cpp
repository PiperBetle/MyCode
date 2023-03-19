#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define int loli
using std::cin;using std::cout;
using std::max;using std::min;
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
constexpr venti operator""_vt(uloli x){return venti(x);}
int n,d,m,ans;
bsi b1,b2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>d;
	for(int i=1,x;i<=n;i++)if(cin>>x,x<=d)b1+=x;else b2+=x;
	sort(all(b1),std::greater<>());b1=0ll+b1;for(int i=2;i<siz(b1);i++)b1[i]+=b1[i-1];
	sort(all(b2),std::greater<>());b2=0ll+b2;for(int i=2;i<siz(b2);i++)b2[i]+=b2[i-1];
	for(int i=0;i<siz(b1);i++){
		int p1=i,p2=(n-i+m)/(m+1);
		cmax(ans,b1[p1]+b2[p2<siz(b2)?p2:0]);
	}
	cout<<ans;
	return 0;
}