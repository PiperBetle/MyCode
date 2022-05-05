#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int f[107][2];
constexpr auto MOD=1000000007;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,k,d;cin>>n>>k>>d;
	f[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=std::min(i,k);j++)
		if(j<d)(f[i][0]+=f[i-j][0])%=MOD,(f[i][1]+=f[i-j][1])%=MOD;
		else (f[i][1]+=f[i-j][0]+f[i-j][1])%=MOD;
	cout<<f[n][1];
	return 0;
}