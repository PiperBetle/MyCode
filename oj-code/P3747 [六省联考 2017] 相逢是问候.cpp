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
struct stn{int ls,rs,tag,sum;}s[200007];
int n,m,p,c,a[50007],pt[500007],len;
bool pr[500007],phi[500007];
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%p)if(b&1)t=t*a%p;return t;}
inline int calc_phi(int x){
	int sum=x;
	for(int i=1;i<=len&&pt[i]*pt[i]<=x;i++){
		if(x%pt[i]==0)sum=sum*(pt[i]-1)/pt[i];
		while(x%pt[i]==0)x/=pt[i];
	}
	if(x>1)sum=sum*(x-1)/x;
}
#define mid ((s[now].ls+s[now].rs)>>1)
void push_up(int now){
	s[now].sum=s[now<<1].sum+s[now<<1|1].sum;
	s[now].tag=std::min(s[now<<1].tag,s[now<<1|1].tag);
}
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now].sum=a[l];return;}
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	push_up(now);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j;
	n=read(),m=read(),p=read(),c=read();
	for(i=1;i<=n;i++)a[i]=read();
	for(pr[1]=true,phi[1]=1,i=2;i<=10000000;i++){
		if(!pr[i])pt[++len]=i,phi[i]=i-1;
		for(j=1;j<=len&&i*pt[j]<=10000000;j++){
			pr[i*pt[j]]=true;
			if(i%pt[j]==0){phi[i*pt[j]]=phi[i]*pt[j];break;}
			else phi[i*pt[j]]=phi[i]*(pt[j]-1);
		}
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}