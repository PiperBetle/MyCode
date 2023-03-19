//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#if __cplusplus>=202002L
#include<ranges>
namespace vw=std::views;
#endif
struct _time{~_time(){std::cerr<<"\n\033[33;40m"<<1.*clock()/CLOCKS_PER_SEC<<"s\033[37;40m";}}_TM;
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x...) {x;continue;}
#define break(x...) {x;break;}
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any&x,const any&y){if(y<x)x=y;}
template<typename any>inline void cmax(any&x,const any&y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmin(any&x,const any&y,const args&...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any&x,const any&y,const args&...z){cmax(x,y);cmax(x,z...);}
using loli=long long;
using unt=unsigned;
using lolu=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsl=std::basic_string<loli>;
using bsc=std::string;
using std::operator""s;
#if __cplusplus>=201703L
using bscv=std::string_view;
using std::operator""sv;
#endif
std::mt19937 rng(std::random_device{}());
#define type std::pair<T1,T2>
template<typename T1,typename T2>std::istream&operator>>(std::istream&x,type&y){return x>>y.fi>>y.se;}
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&x,const type&y){return x<<y.fi<<' '<<y.se;}
template<typename T1,typename T2>type operator+(const type&x,const type&y){return{x.fi+y.fi,x.se+y.se};}
template<typename T1,typename T2>type operator+=(type&x,const type&y){x.fi+=y.fi;x.se+=y.se;return x;}
template<typename T1,typename T2>type operator-(const type&x,const type&y){return{x.fi-y.fi,x.se-y.se};}
template<typename T1,typename T2>type operator-=(type&x,const type&y){x.fi-=y.fi;x.se-=y.se;return x;}
#undef type
template<typename any>any get(std::istream&x=cin){any y;x>>y;return y;}
template<typename any>any&STLcls(any &x){any{}.swap(x);return x;}
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=2001;
int n,m,k,bg;
char a[N][N];
std::vector<std::pair<pii,pii>>ans;
std::vector<pii>b[26];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		for(int c=0;c<26;c++)b[c].clear();
		ans.clear();
		cin>>n>>m;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			if(cin>>a[i][j],a[i][j]!='.')
				b[a[i][j]-'a'].emplace_back(i,j);
		k=-1;
		for(int c=0;c<26;c++)if(!b[c].empty())k=c;
		if(k==-1)continue(cout<<"YES\n0\n");
		for(int c=k;~c;c--)if(!b[c].empty())bg=c;
		for(int c=k;~c;c--){
			if(siz(b[c])==0)continue(ans.emplace_back(b[bg][0],b[bg][0]))
			if(siz(b[c])==1)continue(ans.emplace_back(b[c][0],b[c][0]));
			sort(all(b[c]));
			auto[x1,y1]=b[c].front();auto[x2,y2]=b[c].back();
			if(x1!=x2&&y1!=y2)goto NO;
			if(x1==x2){
				for(int j=y1;j<=y2;j++)
					if(a[x1][j]!='#'&&a[x1][j]!=c+'a')goto NO;
					else a[x1][j]='#';
				for(int x:b[c]|vw::keys)
					if(x!=x1)goto NO;
			}else{
				for(int i=x1;i<=x2;i++)
					if(a[i][y1]!='#'&&a[i][y1]!=c+'a')goto NO;
					else a[i][y1]='#';
				for(int y:b[c]|vw::values)
					if(y!=y1)goto NO;
			}
			for(auto[x,y]:b[c])if(a[x][y]!='#')goto NO;
			ans.emplace_back(b[c].front(),b[c].back());
		}
		cout<<"YES\n"<<k+1<<'\n';
		for(cauto&i:ans|vw::reverse)cout<<i<<'\n';
		continue;
		NO:cout<<"NO\n";
	}
	return 0;
}