#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
constexpr int MOD=1000000007;
using std::cin;using std::cout;
int f[2007][2007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,s,t;cin>>n>>s>>t;f[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(i==s||i==t)f[i][j]=(f[i-1][j]+f[i-1][j-1])%MOD;
		else f[i][j]=((j-(i>s)-(i>t))*f[i-1][j-1]+j*f[i-1][j+1])%MOD;
	}
	cout<<f[n][1];
	return 0;
}