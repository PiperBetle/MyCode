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
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
constexpr int N=101;
int n,m1,m2,a[N],f[2][N][N][2];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;m1=(n+1)/2,m2=n/2;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(f[0],0x3f,sizeof f[0]);
	f[0][0][0][0]=f[0][0][0][1]=0;
	for(int i=1;i<=n;i++){
		memset(f[i&1],0x3f,sizeof f[i&1]);
#define k (i-j)
		if(!a[i]||a[i]&1)for(int j=1;j<=i;j++)
			cmin(f[i&1][j][k][1],f[~i&1][j-1][k][1],f[~i&1][j-1][k][0]+1);
		if(!a[i]||~a[i]&1)for(int j=0;j<i;j++)
			cmin(f[i&1][j][k][0],f[~i&1][j][k-1][0],f[~i&1][j][k-1][1]+1);
#undef k
	}
	cout<<std::min(f[n&1][m1][m2][0],f[n&1][m1][m2][1]);
	return 0;
}