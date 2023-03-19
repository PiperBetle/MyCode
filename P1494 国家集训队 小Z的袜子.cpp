#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<numeric>
#define int long long
using std::cin;using std::cout;
int a[500007],b[500007],cnt[500007],l=1,r=0,now=0;;
struct ask{int l,r,id;bool operator<(const ask &t){return b[l]==b[t.l]?r<t.r:b[l]<b[t.l];}}q[500007];
struct result{int fz,fm;}ans[500007];
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
inline void add(int x){now+=cnt[a[x]];cnt[a[x]]++;}
inline void del(int x){cnt[a[x]]--;now-=cnt[a[x]];}
signed main()
{
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	int n=read(),m=read(),len=sqrt(n),num=ceil(1.*n/len);
	for(int i=1;i<=num;i++)for(int j=(i-1)*len+1;j<=i*len;j++)b[j]=i;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	std::sort(q+1,q+1+m);
	for(int i=1;i<=m;i++){
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		if(q[i].l==q[i].r){ans[q[i].id].fz=0;ans[q[i].id].fm=1;continue;}
		ans[q[i].id].fz=now,ans[q[i].id].fm=(q[i].r-q[i].l)*(q[i].r-q[i].l+1)/2;
	}
	for(int i=1;i<=m;i++){
		int g=std::gcd(ans[i].fz,ans[i].fm);
		if(g!=0)ans[i].fz/=g,ans[i].fm/=g;
		printf("%lld/%lld\n",ans[i].fz,ans[i].fm);
	}
	return 0;
}