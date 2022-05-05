#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 1000000007ull
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
unsigned long long pw[300007];int n;
#define mid ((l+r)>>1)
struct stn{int len;unsigned long long data;}s1[1200007],s2[1200007];
stn operator+(stn x,stn y){return stn{x.len+y.len,(x.data*pw[y.len]+y.data)%mod};}
void build(int now,int l,int r){
	if(l==r){s1[now].len=s2[now].len=1;return;}
	build(now<<1,l,mid);build(now<<1|1,mid+1,r);
	s1[now]=s1[now<<1]+s1[now<<1|1];
	s2[now]=s2[now<<1|1]+s2[now<<1];
}
void change(int now,int l,int r,int k){
	if(l==r){s1[now].data=s2[now].data=1ull;return;}
	if(k<=mid)change(now<<1,l,mid,k);
	else change(now<<1|1,mid+1,r,k);
	s1[now]=s1[now<<1]+s1[now<<1|1];
	s2[now]=s2[now<<1|1]+s2[now<<1];
}
stn query1(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s1[now];
	if(y<=mid)return query1(now<<1,l,mid,x,y);
	if(x>mid)return query1(now<<1|1,mid+1,r,x,y);
	return query1(now<<1,l,mid,x,mid)+query1(now<<1|1,mid+1,r,mid+1,y);
}
stn query2(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s2[now];
	if(y<=mid)return query2(now<<1,l,mid,x,y);
	if(x>mid)return query2(now<<1|1,mid+1,r,x,y);
	return query2(now<<1|1,mid+1,r,mid+1,y)+query2(now<<1,l,mid,x,mid);
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,m,k;n=read();
	for(pw[0]=i=1;i<=n;i++)pw[i]=pw[i-1]*19260817ull%mod;
	build(1,1,n);
	for(i=1;i<=n;i++){
		change(1,1,n,m=read());k=std::min(m-1,n-m);
		if(k>0&&query1(1,1,n,m-k,m-1).data!=query2(1,1,n,m+1,m+k).data)
			return puts("YES"),0;
	}
	puts("NO");
	return 0;
}