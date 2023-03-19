#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
struct stn{
	int sum=0;bool all=0,lax=0,rax=0;
	friend stn operator+(const stn &x,const stn &y){
		return stn{x.sum+y.sum+(x.rax&&y.lax),x.all&&y.all,x.lax||(x.all&&y.lax),y.rax||(y.all&&x.rax)};
	}
}s[800007];
#define mid ((l+r)>>1)
#define ls (now<<1)
#define rs (now<<1|1)
int n,m;
void build(int now,int l,int r){
	if(l==r){s[now]={0,l!=1&&l!=n,l==n,l==1};return;}
	build(ls,l,mid);build(rs,mid+1,r);s[now]=s[ls]+s[rs];
}
void change(int now,int l,int r,int x,char c){
	if(l==r){s[now]={0,c=='X',c==')',c=='('};return;}
	x<=mid?change(ls,l,mid,x,c):change(rs,mid+1,r,x,c);s[now]=s[ls]+s[rs];
}
stn query(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[now];
	if(y<=mid){return query(ls,l,mid,x,y);}if(x>mid){return query(rs,mid+1,r,x,y);}
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	char c;cin>>n>>m;build(1,1,n);
	while(m--){
		int t,x,y;cin>>t;
		switch(t){
		case 1:cin>>x>>c;change(1,1,n,x,c);break;
		case 2:cin>>x>>y;cout<<query(1,1,n,x,y).sum<<'\n';break;
		}
	}
	return 0;
}