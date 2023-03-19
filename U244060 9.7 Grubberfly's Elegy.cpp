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
constexpr int N=301;
int n,m,k,a[N*N],ans;
bool f[N*N];
inline int sum(int i,int j){return i<=j?a[j]-a[i-1]:0;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[++k];
	std::sort(a+1,a+1+k);
	for(int i=1;i<=k;i++)a[i]+=a[i-1];
	ans=abs(a[k]);f[0]=1;
	for(int i=1;i<=k;i++){
		if(i>=n)f[i]|=f[i-n];
		if(i>=m)f[i]|=f[i-m];
		if(f[i])ans=std::max(ans,sum(i+1,k)-sum(1,i));
	}
	cout<<ans;
	return 0;
}