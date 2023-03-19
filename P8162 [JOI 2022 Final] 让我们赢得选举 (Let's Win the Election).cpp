#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=501;
constexpr double inf=1e100;
int n,m,b[N];
pii a[N];
double f[N][N],ans=inf;
template<typename any>inline void cmin(any &x,any y){if(x>y)x=y;}
void solve(int x){
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=inf;
	f[0][0]=0;
	for(int i=1;i<=n;i++)b[i]=a[i].fi;
	for(int i=1;i<=n;i++)for(int j=0;j<=std::min(x,i);j++){
		f[i][j]=f[i-1][j]+1.*a[i].fi/(x+1);
		if(j&&~a[i].se)cmin(f[i][j],f[i-1][j-1]+1.*a[i].se/j);
	}
	for(int i=m;i<=n;i++)cmin(ans,f[i][x]);
	for(int i=m-1;i>=x;i--){
		std::sort(b+1+i,b+1+n);
		double sum=0;
		for(int j=i+1;j<=m;j++)sum+=b[j];
		cmin(ans,f[i][x]+1.*sum/(x+1));
	}		
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se;
	std::sort(a+1,a+1+n,[](const pii &x,const pii &y){
		return ~x.se&&~y.se?x.se<y.se:x.se>y.se;
	});
	for(int i=0;i<=m;i++)solve(i);
	cout<<ans;
	return 0;
}