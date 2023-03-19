#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2002;
int n,m,ans,a[kN][kN],up[kN][kN],dw[kN][kN],lf[kN][kN],rt[kN][kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		char c;cin>>c;a[i][j]=c=='.';
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(a[i][j])up[i][j]=up[i-1][j]+1;
	for(int i=n;i>=1;i--)for(int j=1;j<=m;j++)
		if(a[i][j])dw[i][j]=dw[i+1][j]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(a[i][j])lf[i][j]=lf[i][j-1]+1;
	for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)
		if(a[i][j])rt[i][j]=rt[i][j+1]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j])
		ans=std::max(ans,up[i][j]+dw[i][j]+lf[i][j]+rt[i][j]-3);
	cout<<ans;
	return 0;
}