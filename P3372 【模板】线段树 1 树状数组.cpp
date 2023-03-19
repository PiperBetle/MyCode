#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int lowbit(int x){return x&-x;}
int n,t1[100007],t2[100007];
inline void add(int c[],int x,int k){for(;x<=n;x+=lowbit(x))c[x]+=k;}
inline int query(int c[],int x,int sum=0){for(;x;x-=lowbit(x))sum+=c[x];return sum;}
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
int sta[70];
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
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,t,pre=0,m,l,r;
	n=read();m=read();
	for(i=1;i<=n;i++)t=read(),add(t1,i,t-pre),add(t2,i,(t-pre)*(i-1)),pre=t;
	while(m--){
		t=read();l=read();r=read();
		if(t==2)write(query(t1,r)*r-query(t2,r)-query(t1,l-1)*(l-1)+query(t2,l-1)),putchar('\n');
		else t=read(),add(t1,l,t),add(t1,r+1,-t),add(t2,l,t*(l-1)),add(t2,r+1,t*-r);
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}