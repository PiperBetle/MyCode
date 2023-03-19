#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cin;using std::cout;
constexpr int MOD=1000000007,kN=1001,kM=201;
inline int add0(int x,int y){return (x+=y)<MOD?x:x-MOD;}
inline int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
std::string a,b;
int f[kM][kM],g[kM][kM],n,m,l;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>l;
	a.reserve(kN),b.reserve(kM);
	cin>>a>>b;a='~'+a;b='~'+b;
	f[0][0]=g[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)for(int k=1;k<=l;k++){
		f[j][k]=(a[i]==b[j]?add0(f[j-1][k],g[j-1][k-1]):0);
		add1(g[j][k],f[j][k]);
	}
	cout<<g[m][l];
	return 0;
}