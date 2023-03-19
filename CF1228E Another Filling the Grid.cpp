#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 1000000007
using std::cin;using std::cout;
int fac[5007],inv[5007];
inline int qp(int a,int p,int t=1){for(;p;p>>=1,a=a*a%MOD)if(p&1)t=t*a%MOD;return t;}
inline int binom(int n,int m){return fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=5000;i++)fac[i]=fac[i-1]*i%MOD;
	inv[5000]=qp(fac[5000],MOD-2);
	for(int i=4999;i>=2;i--)inv[i]=inv[i+1]*(i+1)%MOD;
	for(int i=0,op=1;i<=n;i++,op=-op)
		ans=(ans+op*binom(n,i)%MOD*qp((qp(m,n-i)*qp(m-1,i)-qp(m-1,n))%MOD,n)%MOD+MOD)%MOD;
	cout<<ans;
	return 0;
}