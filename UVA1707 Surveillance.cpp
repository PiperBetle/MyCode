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
constexpr int N=1e6+1,M=std::__lg(N)+1,inf=0x3f3f3f3f;
int n,m,f[M][2*N],ans=inf;
pii a[N];
template<typename any>inline void chkmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void chkmax(any &x,const any &y){if(x<y)x=y;}
signed main(){
//	freopen("ring.in","r",stdin);
//	freopen("ring.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	while(cin>>n>>m){
		for(int i=0;(1<<i)<=m;i++)memset(f[i]+1,0,sizeof(int)*(2*n-1));
		ans=inf;
		for(int i=1;i<=m;i++){
			cin>>a[i].fi>>a[i].se;
			if(a[i].fi<=a[i].se)chkmax(f[0][a[i].fi],a[i].se);
			else chkmax(f[0][a[i].fi],a[i].se+n);
		}
		for(int i=2;i<=2*n-1;i++)if(f[0][i-1]>=i)chkmax(f[0][i],f[0][i-1]);
		for(int i=1;(1<<i)<=m;i++)for(int j=1;j<=2*n-1;j++)
			if(f[i-1][j]>=j&&f[i-1][f[i-1][j]+1]>=f[i-1][j]+1)
				f[i][j]=f[i-1][f[i-1][j]+1];
		for(int k=1;k<=n;k++){
			int p=k,cnt=0;
			for(int i=std::__lg(m);i>=0;i--){
				if(p<=k+n-1&&f[i][p]>k+n-1)ans=std::min(ans,cnt+(1<<i));
				else if(p<=k+n-1&&f[i][p]>=p)p=f[i][p]+1,cnt+=(1<<i);
			}
			if(p>k+n-1)ans=std::min(ans,cnt);
		}
		if(ans==inf)cout<<"impossible\n";else cout<<ans<<'\n';
	}
	return 0;
}