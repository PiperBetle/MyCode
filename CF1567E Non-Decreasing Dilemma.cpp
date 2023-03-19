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
	int w=0,y=1,c=getchar();
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
int a[200007],n;
struct stn{
	int ls,rs,stt,end;long long sum;
	stn():ls(0),rs(0),stt(0),end(0),sum(0ll){}
}s[800007];
inline stn operator+(const stn &x,const stn &y){
	stn t;t.ls=x.ls;t.rs=y.rs;
	t.sum=x.sum+y.sum;t.stt=x.stt;t.end=y.end;
	if(x.stt==x.rs-x.ls+1&&a[x.rs]<=a[y.ls])t.stt+=y.stt;
	if(y.end==y.rs-y.ls+1&&a[x.rs]<=a[y.ls])t.end+=x.end;
	if(a[x.rs]<=a[y.ls])t.sum+=1ll*x.end*y.stt;
	return t;
}
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now].sum=1ll;s[now].stt=s[now].end=1;return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	s[now]=s[now<<1]+s[now<<1|1];
}
void change(int now,int pos,int k){
	if(s[now].ls==pos&&s[now].rs==pos){a[pos]=k;return;}
	int mid=(s[now].ls+s[now].rs)>>1;
	if(pos<=mid)change(now<<1,pos,k);
	if(pos>mid)change(now<<1|1,pos,k);
	s[now]=s[now<<1]+s[now<<1|1];
}
stn query(int now,int l,int r){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now];
	int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid&&r<=mid)return query(now<<1,l,r);
	if(l>mid&&r>mid)return query(now<<1|1,l,r);
	stn t1=query(now<<1,l,r),t2=query(now<<1|1,l,r);return t1+t2;
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,m,l,r,x,y;
	n=read();m=read();
	for(i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	while(m--)
		if(read()==1)x=read(),y=read(),change(1,x,y);
		else l=read(),r=read(),write(query(1,l,r).sum),putchar('\n');
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}