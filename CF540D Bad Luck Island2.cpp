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
constexpr int N=101;
int a,b,c;
double r,s,p,f[N][N][N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>a>>b>>c;f[a][b][c]=1;
	for(int i=a;~i;i--)for(int j=b;~j;j--)for(int k=c;~k;k--){
		double tot=i*j+j*k+i*k;
		if(i&&k)f[i-1][j][k]+=f[i][j][k]*i*k/tot;
		if(i&&j)f[i][j-1][k]+=f[i][j][k]*i*j/tot;
		if(j&&k)f[i][j][k-1]+=f[i][j][k]*j*k/tot;
		if(i&&!j&&!k)r+=f[i][j][k];
		if(!i&&j&&!k)s+=f[i][j][k];
		if(!i&&!j&&k)p+=f[i][j][k];
	}
	printf("%.10f %.10f %.10f",r,s,p);
	return 0;
}