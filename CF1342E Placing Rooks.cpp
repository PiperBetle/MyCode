#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 998244353
using std::cin;using std::cout;
int fac[200007],inv[200007];
inline int qp(int a,int p,int t=1){for(;p;p>>=1,a=a*a%MOD)if(p&1)t=t*a%MOD;return t;}
inline int c(int x,int y){return x<y?0:fac[x]*inv[y]%MOD*inv[x-y]%MOD;}
inline int stirling(int n,int m){
	int ans=0;
	for(int k=0,op=1;k<=m;k++,op=-op)
		ans=(ans+op*c(m,k)%MOD*qp(m-k,n)%MOD+MOD)%MOD;
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,k,ans=0;cin>>n>>k;
	if(k>=n)return cout<<0,0;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
	inv[n]=qp(fac[n],MOD-2);
	for(int i=n-1;i>=2;i--)inv[i]=inv[i+1]*(i+1)%MOD;
	ans=stirling(n,n-k)*c(n,n-k)%MOD;
	cout<<(k?(ans<<1)%MOD:ans);
	return 0;
}