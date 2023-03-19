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
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=101;
int n,m,a[kN][kN];
loli b[kN][kN];
lodb ans=1;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(a,0x3f,sizeof a);
	cin>>n>>m;
	for(int u,v;m--;)cin>>u>>v,b[u][v]=b[v][u]=a[u][v]=a[v][u]=1;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		if(a[i][j]>a[i][k]+a[k][j])a[i][j]=a[i][k]+a[k][j],b[i][j]=b[i][k]*b[k][j];
		else if(a[i][j]==a[i][k]+a[k][j])b[i][j]+=b[i][k]*b[k][j];
	for(int i=2;i<n;i++)if(a[1][i]+a[i][n]==a[1][n])ans=std::max(ans,2.l*b[1][i]*b[i][n]/b[1][n]);
	printf("%.12Lf",ans);
	return 0;
}