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
constexpr int N=1e5+1;
double max[N<<2];
int n,m,sum[N<<2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int query(int u,int l,int r,double k){
	if(max[u]<=k)return 0;
	if(l==r)return max[u]>k;
	if(max[ls]<=k)return query(rs,mid+1,r,k);
	return query(ls,l,mid,k)+sum[u]-sum[ls];
}
void updata(int u,int l,int r,int x,double k){
	if(l==r)return max[u]=k,sum[u]=1,void();
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
	max[u]=std::max(max[ls],max[rs]);
	sum[u]=sum[ls]+query(rs,mid+1,r,max[ls]);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int x,y;m--;){
		cin>>x>>y;
		updata(1,1,n,x,1.*y/x);
		cout<<sum[1]<<'\n';
	}
	return 0;
}