#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ext/pb_ds/assoc_container.hpp>
namespace pbds=__gnu_pbds;
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
constexpr int N=100001,MOD=1e7+19;
constexpr venti operator""_vt(uloli x){return venti(x);}
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
inline int tomod0(int _x){return (_x%=MOD)<0?_x+MOD:_x;}
inline int&tomod1(int&_x){return (_x%=MOD)<0?_x+=MOD:_x;}
int n,m,k,inv[MOD],a[N],b[N],sum,add,mul,ans;
struct{int op,x,k;}q[N];
pbds::gp_hash_table<int,int>mp;
int val(int x){
	if(mp.find(x)==mp.end())return add;
	return add0(mul0(mp[x],mul),add);
}
void solve(cauto&r){
	auto[op,x,k]=r;
	switch(op){
	case 1:sub1(sum,val(x));mp[x]=mul0(sub0(k,add),inv[mul]);add1(sum,k);break;
	case 2:add1(add,k);add1(sum,mul0(n,k));break;
	case 3:mul1(add,k);mul1(mul,k);mul1(sum,k);break;
	case 4:add=k;mul=1;sum=mul0(n,k);mp.clear();break;
	case 5:add1(ans,val(x));break;
	case 6:add1(ans,sum);break;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	inv[1]=1;for(int i=2;i<MOD;i++)inv[i]=mul0(MOD-MOD/i,inv[MOD%i]);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].op;
		if(q[i].op==1||q[i].op==5)cin>>q[i].x;
		if(q[i].op<=4)cin>>q[i].k,tomod1(q[i].k);
		if(q[i].op==3&&!q[i].k)q[i].op=4;
	}
	cin>>k;
	for(int i=1;i<=k;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=k;i++)for(int j=1;j<=m;j++)solve(q[(a[i]+1ll*j*b[i])%m+1]);
	cout<<ans;
	return 0;
}