#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
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
template<typename _Tp>inline _Tp cubic(_Tp x){return x*x*x;}
struct stn{int ls,rs,max,min,sum;}s[2000007];
int a[500007],n;
inline void push_up(int now){
	s[now].sum=s[now<<1].sum+s[now<<1|1].sum;
	s[now].max=std::max(s[now<<1].max,s[now<<1|1].max);
	s[now].min=std::min(s[now<<1].min,s[now<<1|1].min);
}
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now].sum=cubic(s[now].max=s[now].min=read());return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	push_up(now);
}
void change(int now,int pos,int k){
	if(s[now].ls==pos&&s[now].rs==pos){s[now].sum=cubic(s[now].max=s[now].min=k);return;}
	int mid=(s[now].ls+s[now].rs)>>1;
	if(pos<=mid)change(now<<1,pos,k);
	if(pos>mid)change(now<<1|1,pos,k);
	push_up(now);
}
stn query(int now,int l,int r){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now];
	stn ans;ans.min=0x3f3f3f3f3f3f3f3f,ans.sum=ans.max=0ll;
	int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid){
		stn t=query(now<<1,l,r);
		ans.sum+=t.sum;
		ans.max=std::max(ans.max,t.max);
		ans.min=std::min(ans.min,t.min);
	}
	if(r>mid){
		stn t=query(now<<1|1,l,r);
		ans.sum+=t.sum;
		ans.max=std::max(ans.max,t.max);
		ans.min=std::min(ans.min,t.min);
	}
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int l,r,m;
	n=read();m=read();
	build(1,1,n);
	while(m--){
		if(read()==1){l=read(),r=read();change(1,l,r);continue;}
		l=read(),r=read();stn f=query(1,l,r);
		int k=f.sum,h1=f.min-1,h2=f.max;
		h1=h1*(h1+1)>>1,h2=h2*(h2+1)>>1;
		if(k==h2*h2-h1*h1)puts("damushen");
		else puts("yuanxing");
	}
	return 0;
}