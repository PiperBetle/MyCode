#include<iostream>
#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using std::cin;using std::cout;
int n,m,k,f[21][100007],lg[100007];
struct stn{int tag,min;stn *s1,*s2;}*root=nullptr;
inline int st_min(int l,int r){int t=lg[r-l+1];return std::min(f[t][l],f[t][r-(1<<t)+1]);}
inline void build(stn *&now,int l,int r){
	if(now!=nullptr)return;
	stn *t=new stn;t->s1=t->s2=nullptr;t->tag=inf;
	if(r-l+1>=n)t->min=st_min(1,n),now=t;
	else l=(l-1)%n+1,r=(r-1)%n+1,t->min=l<=r?st_min(l,r):std::min(st_min(1,r),st_min(l,n)),now=t;
}
#define mid ((l+r)>>1)
void spread(stn *&now,int l,int r){
	build(now->s1,l,mid);build(now->s2,mid+1,r);
	if(now->tag!=inf)now->s1->min=now->s1->tag=now->s2->min=now->s2->tag=now->tag,now->tag=inf;
}
void change(stn *&now,int l,int r,int x,int y,int k){
	build(now,l,r);if(x<=l&&r<=y){now->min=now->tag=k;return;}
	spread(now,l,r);if(x<=mid)change(now->s1,l,mid,x,y,k);if(y>mid)change(now->s2,mid+1,r,x,y,k);
	now->min=std::min(now->s1->min,now->s2->min);
}
int query(stn *&now,int l,int r,int x,int y){
	build(now,l,r);if(x<=l&&r<=y)return now->min;
	spread(now,l,r);if(y<=mid)return query(now->s1,l,mid,x,y);if(x>mid)return query(now->s2,mid+1,r,x,y);
	return std::min(query(now->s1,l,mid,x,y),query(now->s2,mid+1,r,x,y));
}
signed main(){
//	freopen("ke.in","r",stdin);
//	freopen("ke.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,l,r,x;
	cin>>n>>k;
	for(i=2;i<100007;i++)lg[i]=lg[i>>1]+1;
	for(i=1;i<=n;i++)cin>>f[0][i];
	for(j=1;j<=lg[n];j++)for(i=1;i+(1<<j)-1<=n;i++)
		f[j][i]=std::min(f[j-1][i],f[j-1][i+(1<<(j-1))]);
	cin>>m;while(m--){
		cin>>x>>l>>r;
		if(x==1)cin>>x,change(root,1,n*k,l,r,x);
		else cout<<query(root,1,n*k,l,r)<<'\n';
	}
	return 0;
}