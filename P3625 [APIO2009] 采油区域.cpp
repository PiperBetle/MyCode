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
constexpr int kN=1502;
int n,m,k,ans,sum[kN][kN],f1[kN][kN],f2[kN][kN],f3[kN][kN],f4[kN][kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1,x;i<=n;i++)for(int j=1;j<=m;j++)cin>>x,sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+x;
	for(int i=n;i>=k;i--)for(int j=n;j>=k;j--)sum[i][j]-=sum[i-k][j]+sum[i][j-k]-sum[i-k][j-k];
	for(int i=k;i<=n;i++)for(int j=k;j<=n;j++)f1[i][j]=std::max({sum[i][j],f1[i-1][j],f1[i][j-1]});
	for(int i=k;i<=n;i++)for(int j=m;j>=k;j--)f2[i][j]=std::max({sum[i][j],f2[i-1][j],f2[i][j+1]});
	for(int i=n;i>=k;i--)for(int j=k;j<=m;j++)f3[i][j]=std::max({sum[i][j],f3[i+1][j],f3[i][j-1]});
	for(int i=n;i>=k;i--)for(int j=m;j>=k;j--)f4[i][j]=std::max({sum[i][j],f4[i+1][j],f4[i][j+1]});
	for(int i=k;i<=n-k;i++)for(int j=k;j<=m-k;j++)
		ans=std::max({ans,f1[i][j]+f2[i][j+k]+f3[i+k][m],f1[i][m]+f3[i+k][j]+f4[i+k][j+k],
		f1[i][j]+f2[n][k+j]+f3[i+k][j],f1[n][j]+f2[i][j+k]+f4[i+k][j+k]});
	for(int i=k;i<=n-k;i++)for(int j=2*k;j<=m-k;j++)ans=std::max(ans,f1[n][j-k]+f2[n][j+k]+sum[i][j]);
	for(int i=2*k;i<=n-k;i++)for(int j=k;j<=m-k;j++)ans=std::max(ans,f1[i-k][m]+f3[i+k][m]+sum[i][j]);
	cout<<ans;
	return 0;
}