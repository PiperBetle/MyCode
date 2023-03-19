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
constexpr int N=1e4+1,M=5e2+1,W=5.5e3+1;
int n,m,a[N+1],tr[M+1][W+1];
template<typename any>inline void chkmax(any &x,const any &y){if(x<y)x=y;}
void updata(int x,int y,int k){
	for(int i=x;i<=m+1;i+=i&-i)for(int j=y;j<W;j+=j&-j)chkmax(tr[i][j],k);
}
int query(int x,int y){
	int k=0;
	for(int i=x;i;i-=i&-i)for(int j=y;j;j-=j&-j)chkmax(k,tr[i][j]);
	return k;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=m;j>=0;j--)
		updata(j+1,a[i]+j,query(j+1,a[i]+j)+1);
	cout<<query(m+1,W-1);
	return 0;
}