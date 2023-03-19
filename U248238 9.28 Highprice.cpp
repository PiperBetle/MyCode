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
constexpr int N=1001;
int n,a[N],f[N][N],ans=0x3f3f3f3f;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);memset(f,0x3f,sizeof f);
	f[1][2]=1000/a[1]*a[2];f[2][1]=1000/a[2]*a[1];
	for(int i=3;i<=n;i++)for(int u=i-1,v=1;v<u;v++){
		cmin(f[i][v],f[u][v]+1000/a[i]*a[u]);
		cmin(f[i][u],f[v][u]+1000/a[i]*a[v]);
		cmin(f[u][i],f[u][v]+1000/a[v]*a[i]);
		cmin(f[v][i],f[v][u]+1000/a[u]*a[i]);
	}
	for(int i=1;i<n;i++)cmin(ans,f[i][n]+1000/a[n]*a[i],f[n][i]+1000/a[i]*a[n]);
	cout<<ans;
	return 0;
}