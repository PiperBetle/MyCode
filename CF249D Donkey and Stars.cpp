#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
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
using pli=std::pair<loli,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+2;
constexpr lodb eps=1e-8,inf=1e6;
template<typename any>inline void chkmax(any &x,const any &y){if(x<y)x=y;}
int n,_a,_b,_c,_d,f[N],id[N];
struct stn{
	int max=0;
	stn *ls=nullptr,*rs=nullptr;
	void push_up(){
		if(ls)chkmax(max,ls->max);
		if(rs)chkmax(max,rs->max);
	}
}*rt=new stn;
#define mid ((l+r)/2)
void updata(stn *&u,lodb l,lodb r,lodb x,int k){
	if(!u)u=new stn;
	if(fabsl(l-r)<eps)return chkmax(u->max,k),void();
	x<mid||fabsl(x-mid)<eps?updata(u->ls,l,mid,x,k):updata(u->rs,mid+eps,r,x,k);
	u->push_up();
}
int query(stn *u,lodb l,lodb r,lodb x,lodb y){
	if(!u)return 0;
	if(x<=l&&r<=y)return u->max;
	int res=0;
	if(x<mid||fabsl(l-mid)<eps)chkmax(res,query(u->ls,l,mid,x,y));
	if(y>mid)chkmax(res,query(u->rs,mid+eps,r,x,y));
	return res;
}
#undef mid
char ch;
lodb X[N],Y[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>_a>>ch>>_b>>_c>>ch>>_d;
	for(int i=1,x,y;i<=n;i++){
		cin>>x>>y;
		X[i]=1.l*(1ll*_d*y-1ll*_c*x)/(1ll*_a*_d-1ll*_b*_c);
		Y[i]=1.l*(1ll*_b*y-1ll*_a*x)/(1ll*_b*_c-1ll*_a*_d);
		id[i]=i;
	}
	n++;id[n]=n;
	std::sort(id+1,id+1+n,[](const int &t1,const int &t2){
		return fabsl(X[t1]-X[t2])<eps?Y[t1]<Y[t2]:X[t1]>X[t2];
	});
	for(int i=1;i<=n;i++){
		f[id[i]]=query(rt,-inf,inf,Y[id[i]]+eps,inf+eps)+1;
		updata(rt,-inf,inf,Y[id[i]],f[id[i]]);
	}
	cout<<f[n]-1;
	return 0;
}