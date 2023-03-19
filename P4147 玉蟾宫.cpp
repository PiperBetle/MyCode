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
int n,m,a[kN][kN],up[kN][kN],l[kN][kN],r[kN][kN],ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		char c;cin>>c;
		a[i][j]=(c=='F');
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(a[i][j])l[i][j]=l[i][j-1]+1;
	for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)
		if(a[i][j])r[i][j]=r[i][j+1]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(i>1&&a[i][j]&&a[i-1][j])
			up[i][j]=up[i-1][j]+1,
			l[i][j]=std::min(l[i][j],l[i-1][j]),
			r[i][j]=std::min(r[i][j],r[i-1][j]);
		ans=std::max(ans,(up[i][j]+1)*(l[i][j]+r[i][j]-1));
	}
	cout<<3*ans;
	return 0;
}