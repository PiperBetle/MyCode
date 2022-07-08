#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
int n,m,a[kN];
double f[kN][10],lg[kN];
pii pre[kN][10];
std::basic_string<int>ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][a[i]%10]=lg[i]=log(a[i]);
		for(int j=0;j<=9;j++)if(f[i-1][j]&&f[i-1][j]+lg[i]>f[i][(j*a[i])%10])
			f[i][(j*a[i])%10]=f[i-1][j]+lg[i],pre[i][(j*a[i])%10]={i-1,j};
		for(int j=0;j<=9;j++)if(f[i-1][j]>f[i][j])
			f[i][j]=f[i-1][j],pre[i][j]={i-1,j};
	}
	if(!f[n][m])return cout<<"-1",0;
	for(int x=n,y=m;;){
		auto[nx,ny]=pre[x][y];
		if(f[nx][ny]!=f[x][y]||a[x]%10==1)ans+=a[x];
		if(nx||ny)x=nx,y=ny;else break;
	}
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<' ';
	return 0;
}