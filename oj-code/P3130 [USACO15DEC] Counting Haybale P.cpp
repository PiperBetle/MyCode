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
struct stn{
	int li,ri,sum=0,min=0x3f3f3f3f3f3f3f3f,add=0;
	friend stn operator+(const stn &x,const stn &y){return stn{x.li,y.ri,x.sum+y.sum,std::min(x.min,y.min),0};}
	int num(){return ri-li+1;}
}s[800007];
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((s[now].li+s[now].ri)>>1)
void build(int now,int l,int r){
	s[now].li=l,s[now].ri=r;if(l==r){cin>>s[now].min;s[now].sum=s[now].min;return;}
	build(ls,l,mid);build(rs,mid+1,r);s[now]=s[ls]+s[rs];
}
inline void spread(int now){
	if(!s[now].add)return;
	s[ls].add+=s[now].add;s[rs].add+=s[now].add;
	s[ls].min+=s[now].add;s[rs].min+=s[now].add;
	s[ls].sum+=s[ls].num()*s[now].add;s[rs].sum+=s[rs].num()*s[now].add;
	s[now].add=0;
}
void add(int now,int x,int y,int k){
	if(x<=s[now].li&&s[now].ri<=y){s[now].sum+=s[now].num()*k;s[now].min+=k;s[now].add+=k;return;}
	spread(now);if(x<=mid){add(ls,x,y,k);}if(y>mid){add(rs,x,y,k);}s[now]=s[ls]+s[rs];
}
stn query(int now,int x,int y){
	if(x<=s[now].li&&s[now].ri<=y)return s[now];
	spread(now);if(y<=mid){return query(ls,x,y);}if(x>mid){return query(rs,x,y);}return query(ls,x,y)+query(rs,x,y);
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;build(1,1,n);
	while(m--){
		char t;cin>>t;int x,y,k;
		switch(t){
		case 'P':cin>>x>>y>>k;add(1,x,y,k);break;
		case 'M':cin>>x>>y;cout<<query(1,x,y).min<<'\n';break;
		case 'S':cin>>x>>y;cout<<query(1,x,y).sum<<'\n';break;
		}
	}
	return 0;
}