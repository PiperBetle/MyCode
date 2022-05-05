#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
int sta[50];
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) ((p3-obuf<1000007)?(*p3++=(x)):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=(x)))
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
struct segment_tree{
	int ls,rs,tag,sum;
	inline void reverse(){sum=rs-ls+1-sum;}
}s[400007][20];
int a[400007],n;
inline void spread(int now,int k){
	if(!s[now][k].tag)return;
	s[now<<1][k].tag+=s[now][k].tag;
	s[now<<1|1][k].tag+=s[now][k].tag;
	if(s[now][k].tag&1)s[now<<1][k].reverse(),s[now<<1|1][k].reverse();
	s[now][k].tag=0;
}
void build(int now,int l,int r){
	for(int k=0;k<20;k++)s[now][k].ls=l,s[now][k].rs=r;
	if(l==r){for(int k=0;k<20;k++)if(a[l]&(1<<k))s[now][k].sum=1;return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	for(int k=0;k<20;k++)s[now][k].sum=s[now<<1][k].sum+s[now<<1|1][k].sum;
}
void change(int now,int l,int r,int k){
	if(l<=s[now][k].ls&&s[now][k].rs<=r){s[now][k].reverse();s[now][k].tag++;return;}
	spread(now,k);int mid=(s[now][k].ls+s[now][k].rs)>>1;
	if(l<=mid)change(now<<1,l,r,k);
	if(r>mid)change(now<<1|1,l,r,k);
	s[now][k].sum=s[now<<1][k].sum+s[now<<1|1][k].sum;
}
int qurey(int now,int l,int r,int k,int sum=0){
	// cout<<now<<' '<<l<<' '<<r<<' '<<k<<'\n';
	if(l<=s[now][k].ls&&s[now][k].rs<=r)return s[now][k].sum<<k;
	spread(now,k);int mid=(s[now][k].ls+s[now][k].rs)>>1;
	if(l<=mid)sum+=qurey(now<<1,l,r,k);
	if(r>mid)sum+=qurey(now<<1|1,l,r,k);
	s[now][k].sum=s[now<<1][k].sum+s[now<<1|1][k].sum;
	return sum;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,m,l,r,x,sum=0;
	n=read();
	for(i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	m=read();
	while(m--){
		if(read()==1){
			sum=0;
			l=read();r=read();
			for(i=0;i<20;i++)sum+=qurey(1,l,r,i);
			write(sum);putchar('\n');
		}else{
			l=read();r=read();x=read();
			for(i=0;i<20;i++)if(x&(1<<i))change(1,l,r,i);
		}
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}