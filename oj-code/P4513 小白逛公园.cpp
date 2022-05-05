#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
int sta[50],n;
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) (p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x)))
#endif
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
inline void write(int x){
	if(x==0){putchar('0');return;}
	int len=0;
	if(x<0)x=-x,putchar('-');
	while(x)sta[len++]=x%10+'0',x/=10;
	while(len--)putchar(sta[len]);
}
struct stn{int sum_l,sum_r,tot,ls,rs,ans;}s[2000007];
void push_up(stn &now,stn &ls,stn &rs){
	now.sum_l=std::max(ls.sum_l,ls.tot+rs.sum_l);
	now.sum_r=std::max(rs.sum_r,ls.sum_r+rs.tot);
	now.tot=ls.tot+rs.tot;
	now.ans=std::max({ls.ans,rs.ans,ls.sum_r+rs.sum_l});
}
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now].sum_l=s[now].sum_r=s[now].tot=s[now].ans=read();return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	push_up(s[now],s[now<<1],s[now<<1|1]);
}
void change(int now,int pos,int k){
	if(s[now].ls==s[now].rs){s[now].sum_l=s[now].sum_r=s[now].ans=s[now].tot=k;return;}
	int mid=(s[now].ls+s[now].rs)>>1;
	if(pos<=mid)change(now<<1,pos,k);
	if(pos>mid)change(now<<1|1,pos,k);
	push_up(s[now],s[now<<1],s[now<<1|1]);
}
stn query(int now,int l,int r){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now];
	int mid=(s[now].ls+s[now].rs)>>1;
	if(r<=mid)return query(now<<1,l,r);
	if(l>mid)return query(now<<1|1,l,r);
	stn t,t1=query(now<<1,l,r),t2=query(now<<1|1,l,r);
	push_up(t,t1,t2);return t;
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int m,l,r,pos,k;
	n=read();m=read();build(1,1,n);
	while(m--)
		if(read()==2)pos=read(),k=read(),change(1,pos,k);
		else l=read(),r=read(),write(query(1,std::min(l,r),std::max(l,r)).ans),putchar('\n');
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}