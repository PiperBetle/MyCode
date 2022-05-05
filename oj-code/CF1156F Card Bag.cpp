#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 998244353
using std::cin;using std::cout;
int n,b[5007],f[5007][5007],sum[5007][5007],inv[5007]={1,1},ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=2;i<=5000;i++)inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	cin>>n;for(int i=1,t;i<=n;i++)cin>>t,b[t]++;
	for(int i=sum[0][0]=1;i<=n;i++)for(int j=sum[i][0]=1;j<=i;j++){
		f[i][j]=sum[i-1][j-1]*b[i]%MOD*inv[n-j+1]%MOD;
		sum[i][j]=(f[i][j]+sum[i-1][j])%MOD;
		(ans+=f[i][j]*(b[i]-1)%MOD*inv[n-j]%MOD)%=MOD;
	}
	cout<<ans;
	return 0;
}