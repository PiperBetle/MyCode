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
constexpr int N=52,M=20002;
int n,m,k,sum[N][M],a[N][M],l[N][M],r[N][M];
template<typename any>inline void chkmax(any &x,const any &y){if(x<y)x=y;}
signed main(){
//	freopen("range.in","r",stdin);
//	freopen("range.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j],sum[i][j]=a[i][j]+sum[i][j-1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-k+1;j++){
			int v=std::max(l[i-1][j-1],r[i-1][j+k])+sum[i][j+k-1]-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1];
			chkmax(l[i][j+k-1],v);
			chkmax(r[i][j],v);
		}
		for(int j=1;j<=m;j++)chkmax(l[i][j],l[i][j-1]);
		for(int j=m;j>=1;j--)chkmax(r[i][j],r[i][j+1]);
		for(int j=m;j>=1;j--)chkmax(l[i][j-1],l[i][j]-a[i+1][j]);
		for(int j=1;j<=m;j++)chkmax(r[i][j+1],r[i][j]-a[i+1][j]);
	}
	cout<<l[n][m];
	return 0;
}