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
constexpr int N=201;
int n1,n2,n3,a[N],b[N],c[N],f[N][N][N];
inline int dfs(int i,int j,int k){
	int &res=f[i][j][k];
	if(~res)return res;else res=0;
	if(i&&j)cmax(res,dfs(i-1,j-1,k)+a[i]*b[j]);
	if(i&&k)cmax(res,dfs(i-1,j,k-1)+a[i]*c[k]);
	if(j&&k)cmax(res,dfs(i,j-1,k-1)+b[j]*c[k]);
	return res;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n1>>n2>>n3;
	for(int i=1;i<=n1;i++)cin>>a[i];
	for(int i=1;i<=n2;i++)cin>>b[i];
	for(int i=1;i<=n3;i++)cin>>c[i];
	std::sort(a+1,a+1+n1);
	std::sort(b+1,b+1+n2);
	std::sort(c+1,c+1+n3);
	memset(f,-1,sizeof f);
	cout<<dfs(n1,n2,n3);
	return 0;
}