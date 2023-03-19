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
#define rall(x) (x).rbegin(),(x).rend()
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x) {x;continue;}
#define break(x) {x;break;}
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
constexpr bool ying=false,yang=true;
constexpr int N=200001;
int n,l,r,a[N][2],f[N][2];
char c;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;l=1,r=n;
		memset(f+1,0,sizeof(f[0])*n);
		for(int i=1;i<=n;i++)cin>>c,a[i][0]=c=='*';
		for(int i=1;i<=n;i++)cin>>c,a[i][1]=c=='*';
		while(!a[l][0]&&!a[l][1])l++;
		while(!a[r][0]&&!a[r][1])r--;
		for(int i=l;i<=r;i++)
			f[i][0]=min(f[i-1][0]+a[i][1]+1,f[i-1][1]+2),
			f[i][1]=min(f[i-1][1]+a[i][0]+1,f[i-1][0]+2);
		cout<<min(f[r][0],f[r][1])-1<<'\n';
	}
	return 0;
}