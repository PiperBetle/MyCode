#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=401,inf=0x3f3f3f3f;
int n,m,f1[kN][kN],f2[kN][kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f1[i][j]=inf,f2[i][j]=1;
	for(int u,v;m--;)cin>>u>>v,f1[u][v]=f1[v][u]=1,f2[u][v]=f2[v][u]=inf;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		f1[i][j]=std::min(f1[i][j],f1[i][k]+f1[k][j]),
		f2[i][j]=std::min(f2[i][j],f2[i][k]+f2[k][j]);
	cout<<[](int x){return x<inf?x:-1;}(std::max(f1[1][n],f2[1][n]));
	return 0;
}