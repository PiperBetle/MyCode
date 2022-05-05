#include<iostream>
#include<cstdio>
#include<algorithm>
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
int bx[200007],by[200007],n,tree[200007];
inline int lowbit(int x){return x&-x;}
inline void add(int x,int k=1){for(;x<=n;x+=lowbit(x))tree[x]+=k;}
inline long long query(int x,long long sum=0){for(;x;x-=lowbit(x))sum+=tree[x];return sum;}
struct point{int x,y;bool operator<(const point &n){return y==n.y?x<n.x:y>n.y;}}a[200007];
bool vis[200007];
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;long long ans=0ll;n=read();
	for(i=1;i<=n;i++)bx[i]=a[i].x=read(),by[i]=a[i].y=read();
	std::sort(bx+1,bx+1+n);int lx=std::unique(bx+1,bx+1+n)-bx-1;
	std::sort(by+1,by+1+n);int ly=std::unique(by+1,by+1+n)-by-1;
	for(i=1;i<=n;i++)a[i].x=std::lower_bound(bx+1,bx+1+lx,a[i].x)-bx,a[i].y=std::lower_bound(by+1,by+1+ly,a[i].y)-by;
	std::sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		if(!vis[a[i].x])add(a[i].x),vis[a[i].x]=true;
		if(i<n&&a[i].y==a[i+1].y)continue;
		for(j=i;j>=1;j--)if(a[j-1].y!=a[j].y)break;
		for(k=0;j<=i;j++)ans+=(query(n)-query(a[j].x-1))*(query(a[j].x)-query(k)),k=a[j].x;
	}
	printf("%lld",ans);
	return 0;
}