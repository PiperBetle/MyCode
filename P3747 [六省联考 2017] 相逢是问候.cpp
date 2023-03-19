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
constexpr int N=5e4+1,D=60;
std::basic_string<int>phi;
int n,m,P,c,sum[N<<2],min[N<<2],c1[D][1<<15],c2[D][1<<15],a[N][D];
int mul(int _x,int _y,int _p){
	loli _z=1ll*_x*_y;
	return int(_z>=_p?_z%_p+_p:_z);
}
int get_phi(int n){
	int ans=n;
	for(int i=2;i*i<=n;i++)if(n%i==0){
		ans-=ans/i;
		while(n%i==0)n/=i;
	}
	return n>1?ans-ans/n:ans;
}
int qp(int _x,int _y){return mul(c1[_y][_x&32767],c2[_y][_x>>15],phi[_y]);}
int calc(int x,int cnt,int i){
	if(!cnt)return x%phi[i];
	if(i+1==siz(phi))return !!c;
	return qp(calc(x,cnt-1,i+1),i);
}
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void push_up(int u){
	min[u]=std::min(min[ls],min[rs]);
	if((sum[u]=sum[ls]+sum[rs])>=P)sum[u]-=P;
}
void build(int u,int l,int r){
	if(l==r){sum[u]=a[l][0];return;}
	build(ls,l,mid);build(rs,mid+1,r);
	push_up(u);
}
void updata(int u,int l,int r,int x,int y){
	if(min[u]>=siz(phi))return;
	if(l==r){sum[u]=a[l][++min[u]];return;}
	if(x<=mid)updata(ls,l,mid,x,y);
	if(y>mid)updata(rs,mid+1,r,x,y);
	push_up(u);
}
int query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return sum[u];
	int res=0;
	if(x<=mid)res+=query(ls,l,mid,x,y);
	if(y>mid)res+=query(rs,mid+1,r,x,y);
	return res>=P?res-P:res;
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>P>>c;
	phi=P;while(phi.back()>1)phi+=get_phi(phi.back());phi+=1;
	for(int i=0;i<siz(phi);i++){
		c1[i][0]=c2[i][0]=1;
		for(int j=1;j<1<<15;j++)c1[i][j]=mul(c1[i][j-1],c,phi[i]);
		c2[i][1]=mul(c1[i][32767],c,phi[i]);
		for(int j=2;j<1<<15;j++)c2[i][j]=mul(c2[i][j-1],c2[i][1],phi[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=siz(phi);j++)a[i][j]=calc(a[i][0],j,0)%P;
		a[i][0]%=P;
	}
	build(1,1,n);
	for(int t,l,r;m--;)switch(cin>>t>>l>>r,t){
	case 0:updata(1,1,n,l,r);break;
	case 1:cout<<query(1,1,n,l,r)<<'\n';break;
	}
	return 0;
}