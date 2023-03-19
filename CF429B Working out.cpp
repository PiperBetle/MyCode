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
constexpr int kN=1002;
int n,m,a[kN][kN],f1[kN][kN],f2[kN][kN],f3[kN][kN],f4[kN][kN],ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f1[i][j]=a[i][j]+std::max(f1[i-1][j],f1[i][j-1]);
	for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)f2[i][j]=a[i][j]+std::max(f2[i-1][j],f2[i][j+1]);
	for(int i=n;i>=1;i--)for(int j=1;j<=m;j++)f3[i][j]=a[i][j]+std::max(f3[i+1][j],f3[i][j-1]);
	for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)f4[i][j]=a[i][j]+std::max(f4[i+1][j],f4[i][j+1]);
	for(int i=2;i<n;i++)for(int j=2;j<m;j++)
		ans=std::max({ans,f1[i-1][j]+f4[i+1][j]+f3[i][j-1]+f2[i][j+1],f1[i][j-1]+f4[i][j+1]+f3[i+1][j]+f2[i-1][j]});
	cout<<ans;
	return 0;
}