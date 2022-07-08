#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr int MOD=1e9+7,kN=2001;
int fac[kN],inv[kN];
inline int qp(long long a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=a*t%MOD;return t;}
inline int binum(int n,int m){if(n<m)return 0;return fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
signed main(){
//	freopen("bisp.in","r",stdin);
//	freopen("bisp.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<kN;i++)fac[i]=fac[i-1]*i%MOD;
	inv[kN-1]=qp(fac[kN-1],MOD-2);
	for(int i=kN-2;i>=2;i--)inv[i]=inv[i+1]*(i+1)%MOD;
	int n,k;cin>>n>>k;
	for(int i=1;i<=k;i++)cout<<(binum(n-k+1,i)*binum(k-1,i-1))%MOD<<'\n';
	return 0;
}