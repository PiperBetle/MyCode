#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
struct stn{
	int sum,lmx,rmx,ans;
	friend stn operator+(const stn &x,const stn &y){
		return stn{x.sum+y.sum,std::max(x.lmx,x.sum+y.lmx),std::max(y.rmx,x.rmx+y.sum),std::max({x.ans,y.ans,x.rmx+y.lmx})};
	}
}s[2000007];
#define ls (now<<1)
#define rs (now<<1|1)
void build(int now,int l,int r){
	if(l==r){s[now].sum=s[now].lmx=s[now].rmx=s[now].ans=read();return;}int mid=(l+r)>>1;
	build(ls,l,mid);build(rs,mid+1,r);s[now]=s[ls]+s[rs];
}
void change(int now,int l,int r,int x,int k){
	if(l==r){s[now].sum=s[now].lmx=s[now].rmx=s[now].ans=k;return;}int mid=(l+r)>>1;
	if(x<=mid){change(ls,l,mid,x,k);}if(x>mid){change(rs,mid+1,r,x,k);}s[now]=s[ls]+s[rs];
}
stn query(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y){return s[now];}int mid=(l+r)>>1;
	if(y<=mid){return query(ls,l,mid,x,y);}if(x>mid)return query(rs,mid+1,r,x,y);
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n=read(),m=read();build(1,1,n);
	for(int x,y;m--;){
		if(read()==1)x=read(),y=read(),cout<<query(1,1,n,std::min(x,y),std::max(x,y)).ans<<'\n';
		else x=read(),y=read(),change(1,1,n,x,y);
	}
	return 0;
}