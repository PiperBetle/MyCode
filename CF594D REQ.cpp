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
constexpr int N=1e6+1,M=2e5+1,MOD=1e9+7;
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
inline int inv(int _x){return qp(_x,MOD-2);}
inline int div0(int _x,int _y){return mul0(_x,inv(_y));}
template<typename...args>inline int div0(int _x,args..._y){return mul0(_x,inv(mul0(_y...)));}
inline int&div1(int&_x,int _y){return _x=mul0(_x,inv(_y));}
template<typename...args>inline int&div1(int&_x,args..._y){return _x=mul0(_x,inv(mul0(_y...)));}
inline int div0(inlsi _x,inlsi _y){return div0(mul0(_x),mul0(_y));}
inline int&div1(int&_x,inlsi _y){return div1(_x,mul0(_y));}
bool pr[N];
int n,m,mif[N],pre[M],a[M],lst[N],ans[M];
std::basic_string<int>pt;
struct{int l,r,id;}q[N];
struct{
	int dt[M];
	void init(){std::fill_n(dt+1,n+1,1);}
	void add(int x,int k){for(;x<=n;x+=x&-x)mul1(dt[x],k);}
	int query(int x){int k=1;for(;x;x-=x&-x)mul1(k,dt[x]);return k;}
}tr;
void updata(int i){
	for(int x=a[i],p=mif[x];x>1;p=mif[x]){
		tr.add(i,div0(p-1,p));
		if(lst[p])tr.add(lst[p],div0(p,p-1));
		lst[p]=i;
		while(x%p==0)x/=p;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i,mif[i]=i;
		for(int j:pt){
			if(i*j>=N)break;
			pr[i*j]=true,mif[i*j]=j;
			if(i%j==0)break;
		}
	}
	cin>>n;pre[0]=1;tr.init();
	for(int i=1;i<=n;i++)cin>>a[i],pre[i]=mul0(pre[i-1],a[i]);
	cin>>m;for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r,q[i].id=i;
	std::sort(q+1,q+1+m,[](cauto&x,cauto&y){return x.r<y.r;});
	for(int i=1,j=0;i<=m;i++){
		while(j<q[i].r)updata(++j);
		ans[q[i].id]=div0({pre[q[i].r],tr.query(q[i].r)},{pre[q[i].l-1],tr.query(q[i].l-1)});
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}