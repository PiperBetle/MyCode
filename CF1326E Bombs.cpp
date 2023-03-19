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
constexpr int N=300001;
struct{int res=0,tag=0;}s[N<<2];
int n,m,p[N];
#define ls (u*2)
#define rs (u*2+1)
#define mid ((l+r)/2)
void updata(int u,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){s[u].res+=k;s[u].tag+=k;return;}
	if(s[u].tag){
		s[ls].tag+=s[u].tag,s[rs].tag+=s[u].tag;
		s[ls].res+=s[u].tag,s[rs].res+=s[u].tag;
		s[u].tag=0;
	}
	if(x<=mid)updata(ls,l,mid,x,y,k);
	if(y>mid)updata(rs,mid+1,r,x,y,k);
	s[u].res=std::min(s[ls].res,s[rs].res);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen("perm.in","r",stdin);
//	freopen("perm.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;m=n+1;
	for(int i=1,x;i<=n;i++)cin>>x,p[x]=i;
	for(int i=1,x;i<=n;i++){
		while(s[1].res>=0)updata(1,1,n,1,p[--m],-1);
		cout<<m<<' ';cin>>x;
		updata(1,1,n,1,x,1);
	}
	return 0;
}