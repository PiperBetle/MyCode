#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<cmath>
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
constexpr int N=11,inf=0x3f3f3f3f;
int n,m,k,a[N][N],s[N][N];
double f[N][N][N][N][N],v;
constexpr auto sqr(auto x){return x*x;}
inline int sum(int x1,int y1,int x2,int y2){
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
double dfs(int x1,int y1,int x2,int y2,int k){
	double &res=f[x1][y1][x2][y2][k];
	if(res)return res;
	if(k==1)return sqr(sum(x1,y1,x2,y2)-v);
	res=inf;
	for(int o=1;o<k;o++){
		for(int p=x1;p<x2;p++)cmin(res,dfs(x1,y1,p,y2,o)+dfs(p+1,y1,x2,y2,k-o));
		for(int p=y1;p<y2;p++)cmin(res,dfs(x1,y1,x2,p,o)+dfs(x1,p+1,x2,y2,k-o));
	}
	return res;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		cin>>a[i][j],s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	v=1.*s[n][m]/k;
	printf("%.2f",sqrt(dfs(1,1,n,m,k)/k));
	return 0;
}