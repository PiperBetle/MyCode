#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
constexpr int MOD=1000000007;
int fac[200007]={1,1},inv[200007]={1,1};
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
inline int bicon(int n,int m){return fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=2;i<=200000;i++)fac[i]=fac[i-1]*i%MOD;
	inv[200000]=qp(fac[200000],MOD-2);
	for(int i=200000-1;i>=2;i--)inv[i]=inv[i+1]*(i+1)%MOD;
	int n,m,k;cin>>n>>m>>k;
	cout<<bicon(n*m,k)*bicon(k,2)%MOD*(n+m)%MOD*qp(3,MOD-2)%MOD;
	return 0;
}