#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int p,fac[2000007]={1,1},s[2000007],f[2000007];
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%p)if(b&1)t=t*a%p;return t;}
inline int inv(int n){return qp(n,p-2);}
inline int bicon(int n,int m){return fac[n]*inv(fac[m]*fac[n-m]%p)%p;}
inline int lucas(int n,int m){return m?bicon(n%p,m%p)*lucas(n/p,m/p)%p:1;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n>>p;
	for(int i=2,t=i;i<=n;t=++i){while(t%p==0)t/=p;fac[i]=fac[i-1]*i%p;}
	for(int i=1;i<=n;i++)s[i]=f[n+i]=1;
	f[n<<1|1]=1;
	for(int i=n;i>=2;i--)s[i>>1]+=s[i];
	for(int i=n;i>=1;i--)f[i]=lucas(s[i]-1,s[i<<1])*f[i<<1]%p*f[i<<1|1]%p;
	cout<<f[1];
	return 0;
}