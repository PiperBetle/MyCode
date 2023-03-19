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
constexpr int N=2e5+1;
int n,a[2][N],f[2][N];
auto calc(int x){return x>0?x:0;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=0;i<2;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
		a[0][1]=-1;f[0][n]=a[0][n];f[1][n]=a[1][n];
		for(int i=0;i<2;i++)for(int j=n-1;j>=1;j--)f[i][j]=std::max(f[i][j+1]-1,a[i][j]);
		f[0][n]=std::max(f[1][n]-1,a[0][n]);f[1][n]=std::max(f[0][n]-1,a[1][n]);
		for(int i=0;i<2;i++)for(int j=n-1;j>=1;j--)f[i][j]=std::max({f[i][j+1]-1,a[i^1][j]-2*(n-j)-1,a[i][j]});
		int ans=f[0][1]+2*n,now=a[1][1]+1;
		for(int i=2,p=1;i<=n;i++,p^=1)
			ans=std::min(ans,now+calc(f[p][i]-now)+2*(n-i+1)),
			now=std::max(now+1,a[p][i]+1),now=std::max(now+1,a[p^1][i]+1);
		cout<<std::min(now,ans)<<'\n';
	}
	return 0;
}