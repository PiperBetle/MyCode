#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<numeric>
#define int long long
using unint=unsigned int;
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
std::multiset<int>s;
int n,m,a[100007],p[100007],c[100007],d[100007],t1[100007],t2[100007];
inline void exgcd(int a,int b,int &x,int &y){if(!b){x=1,y=0;return;}exgcd(b,a%b,y,x);y-=a/b*x;}
inline int qm(int a,int b,unint p){unint c=(unint)a*b-(unint)(1.l*a/p*b+.5l)*p;return c<p?c:c+p;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int T=read();while(T--){
		n=read(),m=read();s.clear();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)p[i]=read();
		for(int i=1;i<=n;i++)c[i]=read();
		for(int i=1;i<=m;i++)s.insert(read());
		for(int i=1;i<=n;i++){
			auto it=*s.begin()>a[i]?s.begin():--s.upper_bound(a[i]);
			d[i]=*it;s.erase(it);s.insert(c[i]);
		}
		bool f=true;for(int i=1;i<=n;i++)if(p[i]!=1)f=false;
		if(f){int ans=0;for(int i=1;i<=n;i++)ans=std::max(ans,(a[i]-1)/d[i]+1);write(ans);goto ctn;}
		for(int i=1;i<=n;i++){
			int g=std::gcd(d[i],p[i]);
			if(a[i]%g){putchar('-');putchar('1');goto ctn;}
			int x,y;exgcd(d[i],p[i],x,y);
			t2[i]=p[i]/g;t1[i]=qm(a[i]/g,(x%t2[i]+t2[i])%t2[i],t2[i]);
		}
		for(int i=1;i<n;i++){
			int g=std::gcd(t2[i],t2[i+1]);
			if((t1[i+1]-t1[i])%g){putchar('-');putchar('1');goto ctn;}
			int x,y;exgcd(t2[i]/g,t2[i+1]/g,x,y); 
			int n1=qm(x,(t1[i+1]-t1[i])/g,t2[i+1]/g),n2=t2[i]/g*t2[i+1];
			n1=(qm(n1,t2[i],n2)+t1[i])%n2;t1[i+1]=n1;t2[i+1]=n2;
		}
		write(t1[n]);ctn:putchar('\n');
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}