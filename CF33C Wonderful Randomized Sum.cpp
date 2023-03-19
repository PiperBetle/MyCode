#include<iostream>
#include<cstdio>
#include<algorithm>
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
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();while(T--){
		int n=read(),m=0,sum=0,max=0;
		for(int i=1,t;i<=n;i++){
			sum+=t=read();
			m=std::max(m+t,0);
			max=std::max(max,m);
		}
		printf("%d\n",max*2-sum);
	}
	return 0;
}