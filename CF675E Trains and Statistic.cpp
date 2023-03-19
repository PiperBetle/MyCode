#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf;
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
#endif
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
int st[100007][20],n,a[100007],lg[100007],f[100007];
inline int st_max(int x,int y){return a[x]>a[y]?x:y;}
inline int query(int l,int r){int t=lg[r-l+1];return st_max(st[l][t],st[r-(1<<t)+1][t]);}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,j,ans=0ll;
	n=read();
	for(i=1;i<n;i++)a[i]=read(),st[i][0]=i;
	for(i=2;i<100007;i++)lg[i]=lg[i>>1]+1;
	for(j=1;(1<<j)<=n;j++)for(i=1;i+(1<<j)-1<=n;i++)
		st[i][j]=st_max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(i=n-1;i>=1;i--){
		int k=query(i+1,a[i]);
		if(a[i]>=n)f[i]=n-i;
		else f[i]=f[k]+(n-i)-(a[i]-k);
		ans+=f[i];
	}
	printf("%lld",ans);
	return 0;
}