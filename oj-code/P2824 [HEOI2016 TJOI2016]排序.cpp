#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
int sta[50];
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
int n,m,p,a[100007];
struct segment_tree{int ls,rs,sum,tag;inline int num(){return rs-ls+1;}}s[800007];
struct ask{int opt,l,r;}q[100007];
void build(int now,int l,int r,int &k){
	s[now].ls=l,s[now].rs=r;
	s[now].tag=2;
	if(l==r){s[now].sum=a[l]>=k;return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid,k);
	build(now<<1|1,mid+1,r,k);
	s[now].sum=s[now<<1].sum+s[now<<1|1].sum;
}
void spread(int now){
	if(s[now].tag==2)return;
	s[now<<1].tag=s[now<<1|1].tag=s[now].tag;
	int mid=(s[now].ls+s[now].rs)>>1;
	s[now<<1].sum=(mid-s[now].ls+1)*s[now].tag;
	s[now<<1|1].sum=(s[now].rs-mid)*s[now].tag;
	s[now].tag=2;
}
void change(int now,int l,int r,int k){
	if(l<=s[now].ls&&s[now].rs<=r){s[now].sum=s[now].num()*k;s[now].tag=k;return;}
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)change(now<<1,l,r,k);
	if(r>mid)change(now<<1|1,l,r,k);
	s[now].sum=s[now<<1].sum+s[now<<1|1].sum;
}
int query(int now,int l,int r,int sum=0){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now].sum;
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)sum+=query(now<<1,l,r);
	if(r>mid)sum+=query(now<<1|1,l,r);
	return sum;
}
bool check(int mid){
	build(1,1,n,mid);
	for(int i=1;i<=m;i++){
		int cnt=query(1,q[i].l,q[i].r);
		if(!q[i].opt)change(1,q[i].l,q[i].r-cnt,0),change(1,q[i].r-cnt+1,q[i].r,1);
		else change(1,q[i].l,q[i].l+cnt-1,1),change(1,q[i].l+cnt,q[i].r,0);
	}
	return query(1,p,p);
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i;
	n=read();m=read();
	for(i=1;i<=n;i++)a[i]=read();
	for(i=1;i<=m;i++)q[i].opt=read(),q[i].l=read(),q[i].r=read();
	p=read();
	int l=1,r=n,mid,ans=-1;
	while(l<=r)if(check(mid=(l+r)>>1))ans=mid,l=mid+1;else r=mid-1;
	write(ans);
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}