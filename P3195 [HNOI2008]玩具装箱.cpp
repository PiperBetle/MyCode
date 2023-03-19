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
constexpr int N=50001;
int n,m,q[N],l,r;
double a[N],b[N],sum[N],f[N];
inline double X(int i){return b[i];}
inline double Y(int i){return f[i]+b[i]*b[i];}
inline double slope(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}
inline auto sqr(auto x){return x*x;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>sum[i],sum[i]+=sum[i-1];
	for(int i=0;i<=n;i++)a[i]=sum[i]+i,b[i]=a[i]+m+1;
	q[l=r=1]=0;
	for(int i=1;i<=n;i++){
		while(l<r&&slope(q[l],q[l+1])<2*a[i])l++;
		f[i]=f[q[l]]+sqr(a[i]-b[q[l]]);
		while(l<r&&slope(q[r-1],q[r])>slope(i,q[r-1]))r--;
		q[++r]=i;
	}
	cout<<loli(f[n]);
	return 0;
}