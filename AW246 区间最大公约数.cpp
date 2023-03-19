#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
using std::cin;using std::cout;
struct stn{
	long long sum=0,gcd=0;
	friend stn operator+(const stn &x,const stn &y){
		return stn{x.sum+y.sum,std::gcd(x.gcd,y.gcd)};
	}
}s[2000007];
long long a[500007];
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
void build(int now,int l,int r){
	if(l==r){s[now].sum=s[now].gcd=a[l]-a[l-1];return;}
	build(ls,l,mid);build(rs,mid+1,r);s[now]=s[ls]+s[rs];
}
void change(int now,int l,int r,int x,long long k){
	if(l==r){s[now].gcd+=k;s[now].sum+=k;return;}
	x<=mid?change(ls,l,mid,x,k):change(rs,mid+1,r,x,k);s[now]=s[ls]+s[rs];
}
stn query(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[now];
	if(y<=mid){return query(ls,l,mid,x,y);}if(x>mid){return query(rs,mid+1,r,x,y);}
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);while(m--){
		char c;int l,r;long long t;
		switch(cin>>c>>l>>r;c){
		case 'C':cin>>t;change(1,1,n,l,t);if(r<n)change(1,1,n,r+1,-t);break;
		case 'Q':stn x=query(1,1,n,1,l),y;if(l<r)y=query(1,1,n,l+1,r);cout<<llabs(std::gcd(x.sum,y.gcd))<<'\n';
		}
	}
	return 0;
}