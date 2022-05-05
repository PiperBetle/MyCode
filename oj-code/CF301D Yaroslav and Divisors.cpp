#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
std::vector<int>link[200007];
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
int tree[200007],n,a[200007],pos[200007],ans[200007];
struct ask{int l,r,id;bool operator<(const ask &n){return r<n.r;}}q[200007];
inline int lowbit(int x){return x&-x;}
inline void add(int x,int k=1){for(;x<=n;x+=lowbit(x))tree[x]+=k;}
inline int query(int x,int sum=0){for(;x;x-=lowbit(x))sum+=tree[x];return sum;}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,m;n=read(),m=read();
	for(i=1;i<=n;i++)pos[a[i]=read()]=i;
	for(i=1;i<=n;i++)for(j=2;j*a[i]<=n;j++)
		if(pos[j*a[i]]<i)link[i].emplace_back(pos[j*a[i]]);
		else link[pos[j*a[i]]].emplace_back(i);
	for(i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	std::sort(q+1,q+1+m);
	for(i=j=1;i<=n;i++){
		for(int it:link[i])add(it);
		for(;q[j].r==i;j++)ans[q[j].id]=query(q[j].r)-query(q[j].l-1)+q[j].r-q[j].l+1;
	}
	for(i=1;i<=m;i++)write(ans[i]),putchar('\n');
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}