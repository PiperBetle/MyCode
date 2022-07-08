#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int kN=1e6+7,MOD=1e9+7;
int fac[kN],inv[kN];
inline int binom(int n,int m){return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=1ll*a*a%MOD)if(b&1)t=1ll*t*a%MOD;return t;}
signed main(){
//	freopen("horse.in","r",stdin);
//	freopen("horse.out","w",stdout);
	int n,m;cin>>n>>m;
	if((n+m)%3!=0||n>(m<<1)||m>(n<<1))return cout<<0,0;
	int t=(n+m)/3,x=n-t;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=t;i++)fac[i]=1ll*fac[i-1]*i%MOD;
	inv[t]=qp(fac[t],MOD-2);
	for(int i=t-1;i>=2;i--)inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	cout<<binom(t,x);
	return 0;
}