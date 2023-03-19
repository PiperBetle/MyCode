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
constexpr int K=10,MOD=1e9+7;
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
int n,k,f[2][1<<K|1];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;k--;
	f[0][0]=1;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		memset(f[i&1],0,sizeof(int)*(1<<k|1));
		for(int j=0;j<=(1<<k);j++){
			if(x!=2)add1(f[i&1][j&1?2:std::min(j+2,1<<k)],f[~i&1][j]);
			if(x!=4)add1(f[i&1][std::min(j+1,1<<k)],f[~i&1][j]);
		}
	}
	cout<<f[n&1][1<<k];
	return 0;
}