#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
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
std::vector<int>e[400007];
int n,col[400007],df[400007],in[400007],out[400007];
struct segment_tree{int ls,rs;long long data,tag;}s[1600007];
void dfs(int now,int fa){
	in[now]=++df[0];
	df[df[0]]=now;
	for(int it:e[now])if(it!=fa)dfs(it,now);
	out[now]=df[0];
}
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now].data=(1ll<<col[df[l]]);return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	s[now].data=s[now<<1].data|s[now<<1|1].data;
}
void spread(int now){
	if(!s[now].tag)return;
	s[now<<1].data=s[now<<1|1].data=s[now].tag;
	s[now<<1].tag=s[now<<1|1].tag=s[now].tag;
	s[now].tag=0;
}
void change(int now,int l,int r,int k){
	if(l<=s[now].ls&&s[now].rs<=r){s[now].data=s[now].tag=(1ll<<k);return;}
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)change(now<<1,l,r,k);
	if(r>mid)change(now<<1|1,l,r,k);
	s[now].data=s[now<<1].data|s[now<<1|1].data;
}
long long query(int now,int l,int r,long long ans=0){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now].data;
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)ans|=query(now<<1,l,r);
	if(r>mid)ans|=query(now<<1|1,l,r);
	return ans;
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,m,u,v,c;
	n=read();m=read();
	for(i=1;i<=n;i++)col[i]=read();
	for(i=1;i<n;i++)u=read(),v=read(),e[u].emplace_back(v),e[v].emplace_back(u);
	dfs(1,0);
	build(1,1,n);
	while(m--)
		if(read()==1)u=read(),c=read(),change(1,in[u],out[u],c);
		else u=read(),write(__builtin_popcountll(query(1,in[u],out[u]))),putchar('\n');
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}