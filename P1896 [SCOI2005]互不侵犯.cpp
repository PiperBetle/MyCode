#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
int f[11][177][177],s[177],len;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;
	for(int i=0;i<(1<<n);i++)if(!(i&(i<<1))&&!(i&(i>>1)))s[++len]=i;
	f[0][1][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=len;j++)for(int l=0;l<=m;l++){
		int cnt=__builtin_popcountll(s[j]);
		if(l<cnt)continue;
		for(int k=1;k<=len;k++)if(!(s[j]&s[k])&&!(s[j]&(s[k]<<1))&&!(s[j]&(s[k]>>1)))
			f[i][j][l]+=f[i-1][k][l-cnt];
	}
	for(int i=1;i<=len;i++)ans+=f[n][i][m];
	cout<<ans;
	return 0;
}