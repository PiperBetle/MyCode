#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 1000000007
using std::cin;using std::cout;
int a[500007],b[500007],f[500007],g[500007],n;
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;int inv_100=qp(100,MOD-2);
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i],a[i]=inv_100*a[i]%MOD,b[i]=inv_100*b[i]%MOD;
	for(int i=n;i>=1;i--)
		f[i]=a[i]*qp(1-b[i]*g[i+1]%MOD+MOD,MOD-2)%MOD,
		g[i]=(b[i]+a[i]*f[i]%MOD*g[i+1])%MOD;
	for(int i=2;i<=n;i++)(f[i]*=f[i-1])%=MOD;
	cout<<(f[n]%MOD+MOD)%MOD;
	return 0;
}