//不向抑郁与焦虑投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<tuple>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::min;using std::max;
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any>inline void cmin(any &x,const any &y){if(x>y)x=y;}
using loli=long long;
using pii=std::pair<int,int>;
using bsi=std::basic_string<int>;
using bsc=std::string;
constexpr int N=1e5+1,inf=0x3f3f3f3f;
int nim(int x,int y){
	if(x==+1)return y;
	if(y==+1)return x;
	return max(x,y);
}
int xam(int x,int y){
	if(x==-1)return y;
	if(y==-1)return x;
	return min(x,y);
}
int n,m,q,a[N],b[N];
struct{
	int mx[N<<2],mn[N<<2];
	int xm[N<<2],nm[N<<2];
	bool cnt[N<<2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
	void pushup(int u){
		mn[u]=min(mn[ls],mn[rs]);
		mx[u]=max(mx[ls],mx[rs]);
		nm[u]=nim(nm[ls],nm[rs]);
		xm[u]=xam(xm[ls],xm[rs]);
		cnt[u]=cnt[ls]|cnt[rs];
	}
	void build(int u,int l,int r,int(&g)[N]){
		if(l==r){
			nm[u]=1;xm[u]=-1;
			if(g[l]<0)nm[u]=g[l];// 最大负数
			if(g[l]>0)xm[u]=g[l];// 最小正数
			mn[u]=mx[u]=g[l];
			cnt[u]=(g[l]==0);
			return;
		}
		build(ls,l,mid,g);build(rs,mid+1,r,g);
		pushup(u);
	}
	bool ask_cnt(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y)return cnt[u];
		bool res=false;
		if(x<=mid)res|=ask_cnt(ls,l,mid,x,y);
		if(y>mid)res|=ask_cnt(rs,mid+1,r,x,y);
		return res;
	}
	int ask_nm(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y)return nm[u];
		int res=+1;
		if(x<=mid)res=nim(res,ask_nm(ls,l,mid,x,y));
		if(y>mid)res=nim(res,ask_nm(rs,mid+1,r,x,y));
		return res;
	}
	int ask_xm(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y)return xm[u];
		int res=-1;
		if(x<=mid)res=xam(res,ask_xm(ls,l,mid,x,y));
		if(y>mid)res=xam(res,ask_xm(rs,mid+1,r,x,y));
		return res;
	}
	int ask_mn(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y)return mn[u];
		int res=inf;
		if(x<=mid)cmin(res,ask_mn(ls,l,mid,x,y));
		if(y>mid)cmin(res,ask_mn(rs,mid+1,r,x,y));
		return res;
	}
	int ask_mx(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y)return mx[u];
		int res=-inf;
		if(x<=mid)cmax(res,ask_mx(ls,l,mid,x,y));
		if(y>mid)cmax(res,ask_mx(rs,mid+1,r,x,y));
		return res;
	}
#undef ls
#undef rs
#undef mid
}s1,s2;
signed main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	s1.build(1,1,n,a);s2.build(1,1,m,b);
	for(int l1,r1,l2,r2;q--;){
		cin>>l1>>r1>>l2>>r2;
		loli res=-0x3f3f3f3f3f3f3f3f,val1,val2;
		for(int i=1;i<=5;i++){
			if(i==1)val1=s1.ask_mn(1,1,n,l1,r1);
			if(i==2)val1=s1.ask_nm(1,1,n,l1,r1);
			if(i==3)val1=s1.ask_cnt(1,1,n,l1,r1);
			if(i==4)val1=s1.ask_xm(1,1,n,l1,r1);
			if(i==5)val1=s1.ask_mx(1,1,n,l1,r1);
			loli tmp=0x3f3f3f3f3f3f3f3f;
			if(i==2&&val1==+1)continue;
			if(i==3){if(val1)val1=0;else continue;}
			if(i==4&&val1==-1)continue;
			for(int j=1;j<=5;j++){
				if(j==1)val2=s2.ask_mn(1,1,m,l2,r2);
				if(j==2)val2=s2.ask_nm(1,1,m,l2,r2);
				if(j==3)val2=s2.ask_cnt(1,1,m,l2,r2);
				if(j==4)val2=s2.ask_xm(1,1,m,l2,r2);
				if(j==5)val2=s2.ask_mx(1,1,m,l2,r2);
				if(j==2&&val2==+1)continue;
				if(j==3){if(val2)val2=0;else continue;}
				if(j==4&&val2==-1)continue;
				cmin(tmp,val1*val2);
			}
			cmax(res,tmp);
		}
		cout<<res<<'\n';
	}
	return 0;
}