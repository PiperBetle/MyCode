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
constexpr int N=2001;
struct{int d,l,r,u;}a[N][N];
int n,m,ans1=1,ans2=1;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		cin>>a[i][j].d,a[i][j].l=a[i][j].r=j,a[i][j].u=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)if(a[i][j].d!=a[i][j+1].d)a[i][j+1].l=a[i][j].l;
		for(int j=m;j>1;j--)if(a[i][j].d!=a[i][j-1].d)a[i][j-1].r=a[i][j].r;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(i>1&&a[i][j].d!=a[i-1][j].d){
		a[i][j].u=a[i-1][j].u+1;
		cmax(a[i][j].l,a[i-1][j].l);cmin(a[i][j].r,a[i-1][j].r);
		int x=a[i][j].r-a[i][j].l+1,y=min(x,a[i][j].u);
		cmax(ans1,y*y);cmax(ans2,x*a[i][j].u);
	}
	cout<<ans1<<'\n'<<ans2;
	return 0;
}