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
using std::max;using std::min;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=86410,inf=0x3f3f3f3f;
int n,m1,m2,ans=inf,s[N<<2];
struct cow{
	int t1,t2,w;
	friend bool operator<(const cow &x,const cow &y){
		return x.t2<y.t2;
	}
}a[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void updata(int u,int l,int r,int x,int k){
	if(l==r){cmin(s[u],k);return;}
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
	s[u]=min(s[ls],s[rs]);
}
int query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[u];
	int res=inf;
	if(x<=mid)cmin(res,query(ls,l,mid,x,y));
	if(y>mid)cmin(res,query(rs,mid+1,r,x,y));
	return res;
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m1>>m2;m1++,m2++;
	for(int i=1;i<=n;i++)cin>>a[i].t1>>a[i].t2>>a[i].w,a[i].t1++,a[i].t2++,cmax(a[i].t1,m1),cmin(a[i].t2,m2);
	memset(s,0x3f,sizeof s);updata(1,1,m2+1,m1,0);
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)updata(1,1,m2+1,a[i].t2+1,query(1,1,m2+1,a[i].t1,a[i].t2)+a[i].w);
	int ans=query(1,1,m2+1,m2+1,m2+1);cout<<(ans==inf?-1:ans);
	return 0;
}