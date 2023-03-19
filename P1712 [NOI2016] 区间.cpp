#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
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
int n,b[1000007],lb;
struct segment{int l,r,t;bool operator<(const segment &n){return t<n.t;}}a[1000007];
struct stn{int ls,rs,max,add;stn &operator+=(const int &n){max+=n;add+=n;return *this;}}s[4000007];
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;s[now].max=s[now].add=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(now<<1,l,mid);build(now<<1|1,mid+1,r);
	s[now].max=std::max(s[now<<1].max,s[now<<1|1].max);
}
void spread(int now){if(!s[now].add)return;s[now<<1]+=s[now].add;s[now<<1|1]+=s[now].add;s[now].add=0;return;}
void add(int now,int l,int r,int k){
	if(l<=s[now].ls&&s[now].rs<=r){s[now]+=k;return;}
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)add(now<<1,l,r,k);
	if(r>mid)add(now<<1|1,l,r,k);
	s[now].max=std::max(s[now<<1].max,s[now<<1|1].max);
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,j,m,ans=0x3f3f3f3f3f3f3f3f;n=read();m=read();
	for(i=1;i<=n;i++)a[i].l=b[++lb]=read(),a[i].r=b[++lb]=read(),a[i].t=a[i].r-a[i].l;
	std::sort(b+1,b+1+lb);lb=std::unique(b+1,b+1+lb)-b-1;
	for(i=1;i<=n;i++)a[i].l=std::lower_bound(b+1,b+1+lb,a[i].l)-b,a[i].r=std::lower_bound(b+1,b+1+lb,a[i].r)-b;
	std::sort(a+1,a+1+n);build(1,1,lb);
	for(i=j=1;i<=n;i++)for(add(1,a[i].l,a[i].r,1);s[1].max>=m;j++)
		ans=std::min(ans,a[i].t-a[j].t),add(1,a[j].l,a[j].r,-1);
	printf("%lld",ans==0x3f3f3f3f3f3f3f3f?-1:ans);
	return 0;
}