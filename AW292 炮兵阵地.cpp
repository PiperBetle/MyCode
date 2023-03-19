#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int mp[107],f[107][407][407],s[407],l;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++){char c;cin>>c;if(c=='H')mp[i]|=(1<<j);}
	for(int k=0;k<(1<<m);k++)if(!(k&(k<<2))&&!(k&(k<<1))&&!(k&(k>>1))&&!(k&(k>>2)))
		if(!((s[++l]=k)&mp[1]))f[1][0][l]=__builtin_popcount(k);
	for(int i=1;i<=l;i++)for(int j=1;j<=l;j++)if(!(s[i]&s[j])&&!(s[j]&mp[2]))
		f[2][i][j]=std::max(f[2][i][j],f[1][0][i]+__builtin_popcount(s[j]));
	for(int t=3;t<=n;t++)for(int i=1;i<=l;i++)if(!(s[i]&mp[t]))
		for(int j=1;j<=l;j++)if(!(s[i]&s[j]))for(int k=1;k<=l;k++)if(!(s[i]&s[k])&&!(s[j]&s[k]))
			f[t][j][i]=std::max(f[t][j][i],f[t-1][k][j]+__builtin_popcount(s[i]));
	for(int i=1;i<=l;i++)for(int j=1;j<=l;j++)ans=std::max(ans,f[n][i][j]);
	cout<<(ans==0?1:ans);
	return 0;
}