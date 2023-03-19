#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 998244353
using std::cin;using std::cout;
int f[1000007][11];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n;
	f[1][1]=f[1][2]=f[1][3]=f[1][4]=f[1][5]=f[1][6]=f[1][7]=f[1][8]=f[1][9]=1;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		f[i][1]=(f[i-1][1]+f[i-1][2])%MOD;
		for(j=2;j<=8;j++)f[i][j]=(f[i-1][j-1]+f[i-1][j]+f[i-1][j+1])%MOD;
		f[i][9]=(f[i-1][8]+f[i-1][9])%MOD;
	}
	cout<<(f[n][1]+f[n][2]+f[n][3]+f[n][4]+f[n][5]+f[n][6]+f[n][7]+f[n][8]+f[n][9])%MOD;
	return 0;
}