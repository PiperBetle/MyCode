#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<array>
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
constexpr int N=77778,MOD=777777777;
inline int add0(int _x,int _y){return (_x+=_y)<MOD?_x:_x-MOD;}
template<typename...args>inline int add0(int _x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-MOD;}
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
template<typename...args>inline int&add1(int&_x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-=MOD;}
inline int add0(inlsi _x){int _y=0;for(int _i:_x)add1(_y,_i);return _y;}
inline int&add1(int&_x,inlsi _y){return add1(_x,add0(_y));}
inline int sub0(int _x,int _y){return (_x-=_y)<0?_x+MOD:_x;}
template<typename...args>inline int sub0(int _x,args..._y){return (_x-=add0(_y...))<0?_x+MOD:_x;}
inline int&sub1(int&_x,int _y){return (_x-=_y)<0?_x+=MOD:_x;}
template<typename...args>inline int&sub1(int&_x,args..._y){return (_x-=add0(_y...))<0?_x+=MOD:_x;}
inline int sub0(inlsi _x,inlsi _y){return sub0(add0(_x),add0(_y));}
inline int&sub1(int&_x,inlsi _y){return sub1(_x,add0(_y));}
inline int mul0(int _x,int _y){return int(1ll*_x*_y%MOD);}
template<typename...args>inline int mul0(int _x,args..._y){return int(1ll*_x*mul0(_y...)%MOD);}
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%MOD);}
template<typename...args>inline int&mul1(int&_x,args..._y){return _x=int(1ll*_x*mul0(_y...)%MOD);}
inline int mul0(inlsi _x){int _y=1;for(int _i:_x)mul1(_y,_i);return _y;}
inline int&mul1(int&_x,inlsi _y){return mul1(_x,mul0(_y));}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,mul1(_x,_x))if(_y&1)mul1(_t,_x);return _t;}
inline int _inv(int _x){return qp(_x,MOD-2);}
inline int div0(int _x,int _y){return mul0(_x,_inv(_y));}
template<typename...args>inline int div0(int _x,args..._y){return mul0(_x,_inv(mul0(_y...)));}
inline int&div1(int&_x,int _y){return _x=mul0(_x,_inv(_y));}
template<typename...args>inline int&div1(int&_x,args..._y){return _x=mul0(_x,_inv(mul0(_y...)));}
inline int div0(inlsi _x,inlsi _y){return div0(mul0(_x),mul0(_y));}
inline int&div1(int&_x,inlsi _y){return div1(_x,mul0(_y));}
struct node:std::array<std::array<int,4>,4>{
#define a (*this)
	node(){memset(this,0,sizeof(*this));}
	node &operator=(int v){
		for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)
			a[i][j]=(i==v||!v)&&(i==j);
		return *this;
	}
	int sum(){
		int res=0;
		for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)add1(res,a[i][j]);
		return res;
	}
	friend node operator*(const node &x,const node &y){
		node res;
		for(int k=1;k<=3;k++)for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)
			add1(res[i][j],mul0(x[i][k],y[k][j]));
		return res;
	}
#undef a
}a,s[N<<2];
int n,m;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void build(int u,int l,int r){
	if(l==r){s[u]=0;return;}
	build(ls,l,mid);build(rs,mid+1,r);
	s[u]=s[ls]*a*s[rs];
}
void updata(int u,int l,int r,int x,int k){
	if(l==r){s[u]=k;return;}
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
	s[u]=s[ls]*a*s[rs];
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
	build(1,1,n);
	for(int x,k;m--;){
		cin>>x>>k;
		updata(1,1,n,x,k);
		cout<<s[1].sum()<<'\n';
	}
	return 0;
}