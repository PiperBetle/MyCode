#include<iostream>
#include<cstdio>
#include<algorithm>
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
int a[200007],b[200007],l[200007],r[200007],f[200007][3],cnt[200007],pos[200007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	for(int T=read();T--;){
		int n=read(),ans=1;for(int i=1;i<=n;i++)a[i]=b[i]=read();
		std::fill(f[1],f[n+1],0);
		std::fill_n(l+1,n,0);std::fill_n(r+1,n,0);std::fill_n(cnt+1,n,0);std::fill_n(pos+1,n,0);
		std::sort(b+1,b+1+n);int len=std::unique(b+1,b+1+n)-b-1;
		for(int i=1;i<=n;i++){
			a[i]=std::lower_bound(b+1,b+1+len,a[i])-b;
			cnt[a[i]]++;r[a[i]]=i;if(!l[a[i]])l[a[i]]=pos[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			f[i][0]=f[pos[a[i]]][0]+1;
			f[i][1]=std::max({f[pos[a[i]-1]][0],f[pos[a[i]]][1],f[pos[a[i]-1]][2]})+1;
			if(i==r[a[i]])f[i][2]=f[l[a[i]]][1]+cnt[a[i]]-1;
			pos[a[i]]=i;
			ans=std::max({ans,f[i][0],f[i][1],f[i][2]});
		}
		printf("%d\n",n-ans);
	}
	return 0;
}