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
inline unsigned gcd(unsigned a,unsigned b){
	if(!a)return b;
	if(!b)return a;
	int t=__builtin_ctz(a|b);
	a>>=__builtin_ctz(a);
	do{
		b>>=__builtin_ctz(b);
		if(a>b)std::swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}
int st[200007][21],a[200007],lg[200007];
inline int query(int l,int r){
	int t=lg[r-l+1];
	return gcd(st[l][t],st[r-(1<<t)+1][t]);
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	fwrite(obuf,p3-obuf,1,stdout);
	int i,j,n=read();
	for(i=1;i<=n;i++)st[i][0]=read();
	for(i=2;i<200007;i++)lg[i]=lg[i>>1]+1;
	for(j=1;(1<<j)<=n;j++)for(i=1;i+(1<<j)-1<=n;i++)
		st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	int l=1,r=0,ans=0;
	for(i=1;i<=n;i++){
		while(l<i&&query(l,i)<i-l+1)l++;
		if(query(l,i)==i-l+1&&l>r)ans++,r=i;
		write(ans);putchar(' ');
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}