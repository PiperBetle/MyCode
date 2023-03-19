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
constexpr int N=5e4+1;
// struct LineBase{
// 	int a[31];
// 	int &operator[](int x){return a[x];}
// 	int operator[](int x)const{return a[x];}
// 	auto &operator+=(int x){for(int i=std::__lg(x);x;i=std::__lg(x^=a[i]))if(!a[i])return a[i]=x,*this;return *this;}
// 	auto clear(){memset(a,0,sizeof a);}
// 	auto &operator=(int x){clear();return *this+=x;}
// 	friend auto operator+(const LineBase &x,const LineBase &y){auto res=x;for(int i=30;~i;i--)if(y[i])res+=y[i];return res;}
// 	auto max(int res=0){for(int i=30;i>=0;i--)res=std::max(res,res^a[i]);return res;}
// }s[N<<2];
template<typename any,int W>struct LineBase{
	using type=LineBase<any,W>;
	any a[W+1];
	any &operator[](int x){return a[x];}
	any operator[](int x)const{return a[x];}
	type &operator+=(any x){for(int i=std::__lg(x);x;i=std::__lg(x^=a[i]))if(!a[i])return a[i]=x,*this;return *this;}
	type &operator+=(const type &y){for(int i=W;~i;i--)if(y[i])*this+=y[i];return *this;}
	friend type operator+(const type &x,const type &y){type res=x;return res+=y;}
	void clear(){memset(a,0,sizeof a);}
	type &operator=(any x){clear();return *this+=x;}
	any max(any res=0){for(int i=W;~i;i--)res=std::max(res,res^a[i]);return res;}
};
LineBase<int,30>s[N<<2];
int n,m;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void updata(int u,int l,int r,int x,int k){
	s[u]+=k;
	if(l==r)return;
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
}
auto query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[u];
	if(y<=mid)return query(ls,l,mid,x,y);
	if(x>mid)return query(rs,mid+1,r,x,y);
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>m>>n;
	for(int l,r;m--;)
		if(cin>>l,l==1)cin>>l>>r,updata(1,1,n,l,r);
		else cin>>l>>r,cout<<query(1,1,n,l,r).max()<<'\n';
	return 0;
}