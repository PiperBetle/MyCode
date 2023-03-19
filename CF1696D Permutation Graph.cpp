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
constexpr int N=2.5e5+1,M=std::__lg(N)+1;
int n,a[N];
pii mn[M][N],mx[M][N];
pii getmn(int l,int r){
	int t=std::__lg(r-l+1);
	return min(mn[t][l],mn[t][r-(1<<t)+1]);
}
pii getmx(int l,int r){
	int t=std::__lg(r-l+1);
	return max(mx[t][l],mx[t][r-(1<<t)+1]);
}
int solve(int l,int r){
	if(l==r)return 0;
	int p1=getmn(l,r).se,p2=getmx(l,r).se;
	if(p1>p2)std::swap(p1,p2);
	return solve(l,p1)+1+solve(p2,r);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],mn[0][i]=mx[0][i]={a[i],i};
		for(int i=1;(1<<i)<=n;i++)for(int j=1;j+(1<<i)-1<=n;j++)
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]),
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
		cout<<solve(1,n)<<'\n';
	}
	return 0;
}