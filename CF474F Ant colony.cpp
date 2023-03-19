#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
using std::cin;using std::cout;
struct stn{int data,sum;}s[400007];
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
inline void push_up(int now){
	s[now].data=std::gcd<unsigned>(s[ls].data,s[rs].data);
	s[now].sum=(s[now].data==s[ls].data?s[ls].sum:0)+(s[now].data==s[rs].data?s[rs].sum:0);
}
inline void build(int now,int l,int r){
	if(l==r){cin>>s[now].data;s[now].sum=1;return;}
	build(ls,l,mid);build(rs,mid+1,r);push_up(now);
}
inline int qgcd(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[now].data;
	if(y<=mid){return qgcd(ls,l,mid,x,y);}if(x>mid){return qgcd(rs,mid+1,r,x,y);}
	return std::gcd<unsigned>(qgcd(ls,l,mid,x,y),qgcd(rs,mid+1,r,x,y));
}
inline int qsum(int now,int l,int r,int x,int y,int g){
	if(x<=l&&r<=y)return s[now].data==g?s[now].sum:0;
	if(y<=mid){return qsum(ls,l,mid,x,y,g);}if(x>mid){return qsum(rs,mid+1,r,x,y,g);}
	return qsum(ls,l,mid,x,y,g)+qsum(rs,mid+1,r,x,y,g);
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q;cin>>n;build(1,1,n);cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		cout<<r-l+1-qsum(1,1,n,l,r,qgcd(1,1,n,l,r))<<'\n';
	}
	return 0;
}