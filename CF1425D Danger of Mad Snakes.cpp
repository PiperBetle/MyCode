#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 1000000007
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
struct snack{int t,x,y;}a[2007];
int sum[2007][2007],n,m,r,ans,fac[2007]={1,1},inv[2007]={1,1};
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
inline int bicon(int n,int m){if(n<m)return 0;return fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
inline int query(int x1,int y1,int x2,int y2){
	x1=std::max(1ll,x1);y1=std::max(1ll,y1);
	x2=std::min(1000ll,x2);y2=std::min(1000ll,y2);
	if(x1>x2||y1>y2)return 0;
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=2;i<=2000;i++)fac[i]=fac[i-1]*i%MOD;
	inv[2000]=qp(fac[2000],MOD-2);
	for(int i=1999;i>=2;i--)inv[i]=inv[i+1]*(i+1)%MOD;
	n=read(),m=read(),r=read();
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read(),a[i].t=read(),sum[a[i].x][a[i].y]++;
	for(int i=1;i<=1000;i++)for(int j=1;j<=1000;j++)sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	for(int i=1;i<=n;i++){
		int t=query(a[i].x-r,a[i].y-r,a[i].x+r,a[i].y+r);
		ans=(ans+a[i].t*a[i].t%MOD*(bicon(n,m)-bicon(n-t,m))%MOD)%MOD;
	}
	for(int i=1;i<=n;i++){
		int t1=query(a[i].x-r,a[i].y-r,a[i].x+r,a[i].y+r);
		for(int j=i+1;j<=n;j++){
			int t2=query(a[j].x-r,a[j].y-r,a[j].x+r,a[j].y+r);
			int t3=query(std::max(a[i].x,a[j].x)-r,std::max(a[i].y,a[j].y)-r,std::min(a[i].x,a[j].x)+r,std::min(a[i].y,a[j].y)+r);
			ans=(ans+2ll*a[i].t*a[j].t%MOD*(bicon(n,m)-bicon(n-t1,m)-bicon(n-t2,m)+bicon(n-t1-t2+t3,m))%MOD)%MOD;
		}
	}
	cout<<(ans+MOD)%MOD;
	return 0;
}