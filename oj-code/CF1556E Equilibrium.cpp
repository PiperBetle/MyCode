#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
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
int a[200007],n,lg[200007];
struct st{
	int min,max;
	st operator+(const st &n){return st{std::min(min,n.min),std::max(max,n.max)};}
}b[20][200007];
st query(int l,int r){int t=lg[r-l+1];return b[t][l]+b[t][r-(1<<t)+1];}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,j,q,l,r;
	n=read();q=read();
	for(i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(i=1;i<=n;i++)a[i]=read();
	for(i=1;i<=n;i++)b[0][i].min=b[0][i].max=a[i]+=a[i-1]-read();
	for(i=1;i<=lg[n];i++)for(j=1;j+(1<<i)-1<=n;j++)
		b[i][j]=b[i-1][j]+b[i-1][j+(1<<(i-1))];
	while(q--){
		l=read(),r=read();st t=query(l,r);
		if(a[r]!=a[l-1]||t.max>a[l-1])write(-1);
		else write(a[l-1]-t.min);
		putchar('\n');
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}