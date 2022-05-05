#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
long long sta[50];
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) (p3-obuf<1000007?*p3++=(x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x)))
#endif
inline int read(){
	long long w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
inline void write(long long x){
	if(x==0){putchar('0');return;}
	int len=0;
	if(x<0)x=-x,putchar('-');
	while(x)sta[len++]=x%10+'0',x/=10;
	while(len--)putchar(sta[len]);
}
int n,m,a[100007];
struct segment_tree{int ls,rs,max;long long sum;}s[800007];
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now].max=s[now].sum=a[l];return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	s[now].max=std::max(s[now<<1].max,s[now<<1|1].max);
	s[now].sum=s[now<<1].sum+s[now<<1|1].sum;
}
void change(int now,int pos,int k){
	if(s[now].ls==pos&&s[now].rs==pos){s[now].max=s[now].sum=k;return;}
	int mid=(s[now].ls+s[now].rs)>>1;
	if(pos<=mid)change(now<<1,pos,k);
	if(pos>mid)change(now<<1|1,pos,k);
	s[now].max=std::max(s[now<<1].max,s[now<<1|1].max);
	s[now].sum=s[now<<1].sum+s[now<<1|1].sum;
}
void mod(int now,int l,int r,int k){
	if(s[now].max<k)return;
	if(s[now].ls==s[now].rs){s[now].max%=k;s[now].sum%=k;return;}
	int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)mod(now<<1,l,r,k);
	if(r>mid)mod(now<<1|1,l,r,k);
	s[now].max=std::max(s[now<<1].max,s[now<<1|1].max);
	s[now].sum=s[now<<1].sum+s[now<<1|1].sum;
}
long long query(int now,int l,int r,long long sum=0){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now].sum;
	int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)sum+=query(now<<1,l,r);
	if(r>mid)sum+=query(now<<1|1,l,r);
	return sum;
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,t,l,r;
	n=read(),m=read();
	for(i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	while(m--){
		t=read();l=read();
		switch(t){
			case 1:r=read();write(query(1,l,r));putchar('\n');break;
			case 2:r=read();t=read();mod(1,l,r,t);break;
			case 3:t=read();change(1,l,t);break;
		}
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}