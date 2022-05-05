#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w;
}
int a[100007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	while(m--){
		int t=read(),l=read(),r=read(),x=read(),ans=0;
		switch(t){
		case 1:for(;l<=r;l++)if(a[l]>x)a[l]-=x;break;
		case 2:for(;l<=r;l++)if(a[l]==x)ans++;printf("%d\n",ans);break;
		}
	}
	return 0;
}