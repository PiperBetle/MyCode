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
struct ask{int x,y,id;inline bool operator<(const ask &n){return y<n.y;}}b[300007];
int a[300007],tree[300007],n,ans[300007];
inline int lowbit(int x){return x&-x;}
inline void add(int x,int k=1){for(;x<=n;x+=lowbit(x))tree[x]+=k;}
inline int query(int x,int sum=0){for(;x;x-=lowbit(x))sum+=tree[x];return sum;}
inline int kth(int k,int x=0){
	// for(int i=1<<std::__lg(n);i;i>>=1)
	for(int i=1<<18;i;i>>=1)
		if(x+i<=n&&k>tree[x+i])k-=tree[x+=i];
	return x+1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	n=read();int m=read();
	for(int i=1;i<=n;i++)a[i]=i-read();
	for(int i=1;i<=m;i++)b[i].x=1+read(),b[i].y=n-read(),b[i].id=i;
	std::sort(b+1,b+1+m);
	for(int i=1,pos=1;i<=m;i++){
		for(;pos<=b[i].y;pos++)add(a[pos]<0?1:std::min(kth(pos-a[pos]),pos+1));
		ans[b[i].id]=b[i].y-query(b[i].x);
	}
	for(int i=1;i<=m;i++)write(ans[i]),putchar('\n');
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}