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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=51;
int n,A,B,c[N],w[N],f[N][N][N][N];
std::basic_string<int>b;
template<typename any>inline void chkmin(any &x,const any &y){if(y<x)x=y;}
template<typename any,typename...args>inline void chkmin(any &x,const any &y,const args &...z){chkmin(x,y);chkmin(x,z...);}
inline int sqr(int x){return x*x;}
int dfs(int l,int r,int x,int y){
	if(~f[l][r][x][y])return f[l][r][x][y];else f[l][r][x][y]=0x3f3f3f3f;
	if(x==0&&y==0){
		chkmin(f[l][r][x][y],A+B*sqr(*std::min_element(c+l,c+1+r)-*std::max_element(c+l,c+1+r)));
		for(int i=1;i<siz(b);i++)for(int j=i;j<siz(b);j++)
			chkmin(f[l][r][x][y],dfs(l,r,i,j)+A+B*sqr(b[i]-b[j]));
	}else{
		if(l==r&&x<=w[l]&&w[l]<=y)f[l][r][x][y]=0;
		for(int k=l;k<r;k++)
			chkmin(f[l][r][x][y],std::min(dfs(l,k,x,y),dfs(l,k,0,0))+std::min(dfs(k+1,r,x,y),dfs(k+1,r,0,0)));
	}
	return f[l][r][x][y];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++)cin>>c[i],b+=c[i];
	std::sort(all(b));b.erase(std::unique(all(b)),b.end());b=0+b;
	for(int i=1;i<=n;i++)w[i]=int(std::lower_bound(all(b),c[i])-b.begin());
	cout<<dfs(1,n,0,0);
	return 0;
}