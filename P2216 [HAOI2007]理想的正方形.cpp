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
constexpr int kN=1002,kM=std::__lg(100)+1;
int a[kN][kN],n,m,r,lgr,mx[kM][kN][kN],mn[kM][kN][kN],ans=0x3f3f3f3f;
int query(int x1,int y1){
	int x2=x1+r-1,y2=y1+r-1;
	int t1=std::max({mx[lgr][x1][y1],mx[lgr][x2-(1<<lgr)+1][y1],mx[lgr][x1][y2-(1<<lgr)+1],mx[lgr][x2-(1<<lgr)+1][y2-(1<<lgr)+1]});
	int t2=std::min({mn[lgr][x1][y1],mn[lgr][x2-(1<<lgr)+1][y1],mn[lgr][x1][y2-(1<<lgr)+1],mn[lgr][x2-(1<<lgr)+1][y2-(1<<lgr)+1]});
	return t1-t2;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>r;lgr=std::__lg(r);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j],mx[0][i][j]=mn[0][i][j]=a[i][j];
	for(int k=1;k<=lgr;k++)for(int i=1;i+(1<<k)-1<=n;i++)for(int j=1;j+(1<<k)-1<=m;j++)
		mx[k][i][j]=std::max({mx[k-1][i][j],mx[k-1][i+(1<<(k-1))][j],mx[k-1][i][j+(1<<(k-1))],mx[k-1][i+(1<<(k-1))][j+(1<<(k-1))]}),
		mn[k][i][j]=std::min({mn[k-1][i][j],mn[k-1][i+(1<<(k-1))][j],mn[k-1][i][j+(1<<(k-1))],mn[k-1][i+(1<<(k-1))][j+(1<<(k-1))]});
	for(int i=1;i+r-1<=n;i++)for(int j=1;j+r-1<=m;j++)ans=std::min(ans,query(i,j));
	cout<<ans;
	return 0;
}