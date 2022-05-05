#include<iostream>
#include<cstring>
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
int n,m,MOD;
struct tree{int li,ri,sum=0,add=0,mul=1;inline int num(){return ri-li+1;}}s[400007];
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((s[now].li+s[now].ri)>>1)
void build(int now,int l,int r){
	s[now].li=l;s[now].ri=r;if(l==r){s[now].sum=read();return;}
	build(ls,l,mid);build(rs,mid+1,r);s[now].sum=(s[ls].sum+s[rs].sum)%MOD;
}
void spread(int now){
	((s[ls].sum*=s[now].mul)+=s[now].add*s[ls].num())%=MOD;((s[rs].sum*=s[now].mul)+=s[now].add*s[rs].num())%=MOD;
	(s[ls].mul*=s[now].mul)%=MOD;(s[rs].mul*=s[now].mul)%=MOD;
	((s[ls].add*=s[now].mul)+=s[now].add)%=MOD;((s[rs].add*=s[now].mul)+=s[now].add)%=MOD;
	s[now].add=0;s[now].mul=1;
}
void add(int now,int l,int r,int k){
	if(l<=s[now].li&&s[now].ri<=r){(s[now].add+=k)%=MOD;(s[now].sum+=s[now].num()*k)%=MOD;return;}
	spread(now);if(l<=mid){add(ls,l,r,k);}if(r>mid){add(rs,l,r,k);}s[now].sum=(s[ls].sum+s[rs].sum)%MOD;
}
void mul(int now,int l,int r,int k){
	if(l<=s[now].li&&s[now].ri<=r){(s[now].mul*=k)%=MOD;(s[now].add*=k)%=MOD;(s[now].sum*=k)%=MOD;return;}
	spread(now);if(l<=mid){mul(ls,l,r,k);}if(r>mid){mul(rs,l,r,k);}s[now].sum=(s[ls].sum+s[rs].sum)%MOD;
}
int query(int now,int l,int r,int sum=0){
	if(l<=s[now].li&&s[now].ri<=r)return s[now].sum;
	spread(now);if(l<=mid){sum+=query(ls,l,r);}if(r>mid){sum+=query(rs,l,r);}return sum%MOD;
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	n=read(),MOD=read();build(1,1,n);
	m=read();while(m--){
		int t=read(),x=read(),y=read();
		switch(t){
		case 1:mul(1,x,y,read());break;
		case 2:add(1,x,y,read());break;
		case 3:printf("%lld\n",query(1,x,y));break;
		}
	}
	return 0;
}