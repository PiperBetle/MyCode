//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<vector>
#if __cplusplus>=202002L
#include<ranges>
using namespace std::views;
#endif
#define siz(x) int(std::size(x))
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define alln(x,n) std::begin(x),std::begin(x)+(n)+1
#define rall(x) std::rbegin(x),std::rend(x)
#define ralln(x,n) std::rbegin(x),std::rbegin(x)+(n)+1
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
using bsc=std::string;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=1001;
int n,m,a[N][N];
std::vector<std::tuple<int,int,int>>ans;
void dfs(int x,int y){
	if(x==0||x==n||y==0||y==m)return;
	int b[4]={a[x][y],a[x][y+1],a[x+1][y],a[x+1][y+1]};
	int p=*std::max_element(all(b));
	if(!p)return;
	for(int i:b)if(i&&i!=p)return;
	ans.emplace_back(x,y,p);
	a[x][y]=a[x][y+1]=a[x+1][y]=a[x+1][y+1]=0;
	for(int i=x-1;i<=x+1;i++)for(int j=y-1;j<=y+1;j++)dfs(i,j);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<n;i++)for(int j=1;j<m;j++)dfs(i,j);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j])return cout<<"-1",0;
	cout<<siz(ans)<<'\n';
	for(auto[x,y,p]:ans|reverse)cout<<x<<' '<<y<<' '<<p<<'\n';
	return 0;
}