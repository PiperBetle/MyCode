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
const int N=17,M=1<<16|1;
int n,a[M][N];
loli f[M],g[M<<2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
inline void solve(int u,int l,int r,int d){
	if(l==r)return;
	solve(ls,l,mid,d-1);
	solve(rs,mid+1,r,d-1);
	for(int i=l;i<=mid;i++)f[i]+=g[rs];
	for(int i=mid+1;i<=r;i++)f[i]+=g[ls];
	for(int i=l;i<=r;i++)g[u]=std::max(g[u],f[i]+a[i][d]);
}
#undef ls
#undef rs
#undef mid
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<1<<n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	solve(1,0,(1<<n)-1,n);cout<<g[1];
	return 0;
}