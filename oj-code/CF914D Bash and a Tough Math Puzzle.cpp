#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
#endif
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
inline unsigned int gcd(unsigned int a,unsigned int b){
	if(!a)return b;
	if(!b)return a;
	int t=__builtin_ctz(a|b);
	a>>=__builtin_ctz(a);
	do{
		b>>=__builtin_ctz(b);
		if(a>b)std::swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}
int a[500007],n,cnt;
struct segment_tree{int ls,rs,gcd;}s[2000007];
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now].gcd=a[l];return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	s[now].gcd=gcd(s[now<<1].gcd,s[now<<1|1].gcd);
}
void change(int now,int pos,int k){
	if(s[now].ls==s[now].rs){s[now].gcd=k;return;}
	int mid=(s[now].ls+s[now].rs)>>1;
	if(pos<=mid)change(now<<1,pos,k);
	if(pos>mid)change(now<<1|1,pos,k);
	s[now].gcd=gcd(s[now<<1].gcd,s[now<<1|1].gcd);
}
void query(int now,int l,int r,int k){
	if(cnt>1||s[now].gcd%k==0)return;
	if(s[now].ls==s[now].rs){cnt++;return;}
	int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)query(now<<1,l,r,k);
	if(r>mid)query(now<<1|1,l,r,k);
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,m,l,r,k;
	n=read();
	for(i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	m=read();
	while(m--)
		if(read()==2)l=read(),k=read(),change(1,l,k);
		else cnt=0,l=read(),r=read(),k=read(),query(1,l,r,k),puts(cnt<2?"YES":"NO");
	return 0;
}