#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int n,a[200007];
struct segment_tree{int ls,rs;long long add;double sin,cos;}s[800007];
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	s[now].add=0;
	if(l==r){s[now].sin=sin(a[l]),s[now].cos=cos(a[l]);return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	s[now].sin=s[now<<1].sin+s[now<<1|1].sin;
	s[now].cos=s[now<<1].cos+s[now<<1|1].cos;
}
inline void updata(segment_tree &a,long long k){
	double sin_k=sin(k),cos_k=cos(k),sin_t=a.sin,cos_t=a.cos;
	a.sin=sin_t*cos_k+cos_t*sin_k;
	a.cos=cos_t*cos_k-sin_t*sin_k;
	a.add+=k;
}
inline void spread(int now){
	if(!s[now].add)return;
	updata(s[now<<1],s[now].add);
	updata(s[now<<1|1],s[now].add);
	s[now].add=0;
}
void add(int now,int l,int r,int k){
	if(l<=s[now].ls&&s[now].rs<=r){updata(s[now],k);return;}
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)add(now<<1,l,r,k);
	if(r>mid)add(now<<1|1,l,r,k);
	s[now].sin=s[now<<1].sin+s[now<<1|1].sin;
	s[now].cos=s[now<<1].cos+s[now<<1|1].cos;
}
double query(int now,int l,int r,double sum=0.){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now].sin;
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)sum+=query(now<<1,l,r);
	if(r>mid)sum+=query(now<<1|1,l,r);
	return sum;
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,m,l,r,t;
	n=read();
	for(i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	m=read();
	while(m--){
		t=read(),l=read(),r=read();
		if(t==1)add(1,l,r,read());
		else printf("%.1lf\n",query(1,l,r));
	}
	return 0;
}