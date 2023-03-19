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
struct stn{int ls,rs,d[32];}s[800007];
int a[200007][32],n,k;
#define mid ((s[now].ls+s[now].rs)>>1)
inline stn operator+(stn a,stn b){for(int i=0;i<(1<<k);i++)a.d[i]=std::max(a.d[i],b.d[i]);a.rs=b.rs;return a;}
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){
		for(int i=0;i<(1<<k);i++)for(int j=s[now].d[i]=0;j<k;j++)
			if(i&(1<<j))s[now].d[i]+=a[l][j];
			else s[now].d[i]-=a[l][j];
		return;
	}
	build(now<<1,l,mid);build(now<<1|1,mid+1,r);
	s[now]=s[now<<1]+s[now<<1|1];
}
void change(int now,int pos){
	if(s[now].ls==s[now].rs){
		for(int i=0;i<(1<<k);i++)for(int j=s[now].d[i]=0;j<k;j++)
			if(i&(1<<j))s[now].d[i]+=a[pos][j];
			else s[now].d[i]-=a[pos][j];
		return;
	}
	if(pos<=mid)change(now<<1,pos);
	if(pos>mid)change(now<<1|1,pos);
	s[now]=s[now<<1]+s[now<<1|1];
}
stn query(int now,int l,int r){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now];
	if(r<=mid)return query(now<<1,l,r);
	if(l>mid)return query(now<<1|1,l,r);
	return query(now<<1,l,r)+query(now<<1|1,l,r);
}
#undef mid
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,j,m,t,l,r;
	n=read(),k=read();
	for(i=1;i<=n;i++)for(j=0;j<k;j++)a[i][j]=read();
	build(1,1,n);m=read();
	while(m--)
		if(read()==1){
			for(t=read(),j=0;j<k;j++)a[t][j]=read();
			change(1,t);
		}else{
			l=read(),r=read();
			stn ans=query(1,l,r);int max=-0x3f3f3f3f;
			for(i=0;i<(1<<(k-1));i++)max=std::max(max,ans.d[i]+ans.d[(1<<k)-1-i]);
			write(max);putchar('\n');
		}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}