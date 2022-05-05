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
struct ask{
	int x,y,pos;
	bool operator<(const ask &n)const{
		if(x!=n.x)return x<n.x;
		if(y!=n.y)return y<n.y;
		return pos<n.pos;
	}
	ask(){}
	ask(int _x,int _y,int _pos):x(_x),y(_y),pos(_pos){}
}s[2500007];
int n,m,b[2500007],tree[2500007],ans[2500007][5],cnt[2500007];
inline int lowbit(int x){return x&-x;}
inline void add(int x,int k=1){for(;x<=n;x+=lowbit(x))tree[x]+=k;}
inline int query(int x,int sum=0){for(;x;x-=lowbit(x))sum+=tree[x];return sum;}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,m,x1,y1,x2,y2;
	n=read(),m=read();
	for(i=1;i<=n;i++)s[i].x=read(),s[i].y=read();
	for(i=1;i<=m;i++)
		x1=read(),y1=read(),x2=read(),y2=read(),
		s[++n]=ask(x1-1,y1-1,i),s[++n]=ask(x1-1,y2,i),
		s[++n]=ask(x2,y1-1,i),s[++n]=ask(x2,y2,i);
	std::sort(s+1,s+1+n);
	for(i=1;i<=n;i++)b[i]=s[i].y;
	std::sort(b+1,b+1+n);
	int l=std::unique(b+1,b+1+n)-b-1;
	for(i=1;i<=n;i++){
		int p=std::lower_bound(b+1,b+1+l,s[i].y)-b;
		if(s[i].pos)ans[s[i].pos][++ans[s[i].pos][0]]=query(p);
		else add(p);
	}
	for(i=1;i<=m;i++)write(ans[i][4]-ans[i][3]-ans[i][2]+ans[i][1]),putchar('\n');
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}