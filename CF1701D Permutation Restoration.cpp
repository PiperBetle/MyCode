//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<queue>
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
constexpr int N=5e5+1;
int n,b[N],c[N],p[N];
pii a[N];
std::priority_queue<pii,std::vector<pii>,std::greater<>>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>b[i],a[i]={i/(b[i]+1)+1,b[i]?i/b[i]:n},p[i]=i;
		std::sort(p+1,p+1+n,[](int x,int y){return a[x]<a[y];});
		for(int i=1,j=1;i<=n;i++){
			for(;j<=n&&a[p[j]].fi==i;j++)q.emplace(a[p[j]].se,p[j]);
			c[q.top().se]=i;q.pop();
		}
		for(int i=1;i<=n;i++)cout<<c[i]<<' ';
		cout<<'\n';
	}
	return 0;
}