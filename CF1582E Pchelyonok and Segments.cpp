#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
constexpr int kN=100000,kM=500,inf=0x3f3f3f3f;
int a[kN+1],sum[kN+1],f[kN+1][kM+1];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T=read();while(T--){
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		std::reverse(a+1,a+1+n);
		std::fill(f[0],f[n+1],0);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		for(int i=0;i<=n;i++){
			f[i][0]=inf;
			for(int j=1;j<=std::min(i,kM);j++)
				if(sum[i]-sum[i-j]>=f[i-j][j-1])f[i][j]=f[i-1][j];
				else f[i][j]=std::max(f[i-1][j],sum[i]-sum[i-j]);
		}
		for(int i=kM;i>=1;i--)if(f[n][i]){cout<<i<<'\n';break;}
	}
	return 0;
}