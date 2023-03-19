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
constexpr int N=3001,MOD=1e9+7;
int n,m,f[N][N][2],ans;
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
inline int mul0(int _x,int _y){return int(1ll*_x*_y%MOD);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;f[0][0][1]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<=std::min(i,m);j++)
		for(int k=0;k<=1;k++)if(f[i-1][j][k]){
			add1(f[i][j][1],mul0(f[i-1][j][k],j));
			add1(f[i][j+k][0],mul0(f[i-1][j][k],m-j));
		}
	for(int i=0;i<=n;i++)add1(ans,f[n][i][1]);
	cout<<ans;
	return 0;
}