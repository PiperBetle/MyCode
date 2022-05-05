#include<iostream>
#include<cstdio>
#include<algorithm>
int st[20][100007],lg[100007];
long long f[100007];
inline int query(int l,int r){int t=lg[r-l+1];return std::min(st[t][l],st[t][r-(1<<t)+1]);}
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w;
}
signed main(){
	int n=read(),c=read();long long sum=0;
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)sum+=st[0][i]=read();
	for(int j=1;j<=lg[n];j++)for(int i=1;i+(1<<j)-1<=n;i++)
		st[j][i]=std::min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	for(int i=c;i<=n;i++)f[i]=std::max(f[i-1],f[i-c]+query(i-c+1,i));
	printf("%lld",sum-f[n]);
	return 0;
}