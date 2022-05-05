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
struct ask{int l,r,id;bool operator<(const ask &n)const{return r<n.r;}}q[1000007];
int s[1000007],n,m,a[1000007],vis[1000007],ans[1000007];
inline int lowbit(int x){return x&-x;}
inline void add(int x,int k=1){for(;x<=n;x+=lowbit(x))s[x]+=k;}
inline int query(int x,int sum=0){for(;x;x-=lowbit(x))sum+=s[x];return sum;}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,j=1;
	n=read();
	for(i=1;i<=n;i++)a[i]=read();
	m=read();
	for(i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	std::sort(q+1,q+1+m);
	for(i=1;i<=m;i++){
		for(;j<=q[i].r;j++){
			if(vis[a[j]])add(vis[a[j]],-1);
			add(vis[a[j]]=j);
		}
		ans[q[i].id]=query(q[i].r)-query(q[i].l-1);
	}
	for(i=1;i<=m;i++)write(ans[i]),putchar('\n');
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}