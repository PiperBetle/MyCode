#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int a[400007],n,MOD;
struct tree{int ls,rs,sum,add,mul;inline int num(){return rs-ls+1;}}s[400007];
void build(int now,int l,int r){
	s[now].add=0;s[now].mul=1;s[now].sum=0;
	s[now].ls=l;s[now].rs=r;
	if(l==r){s[now].sum=a[l];return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	s[now].sum=(s[now<<1].sum+s[now<<1|1].sum)%MOD;
}
void spread(int now){
	((s[now<<1].sum*=s[now].mul)+=s[now].add*s[now<<1].num())%=MOD;
	((s[now<<1|1].sum*=s[now].mul)+=s[now].add*s[now<<1|1].num())%=MOD;
	(s[now<<1].mul*=s[now].mul)%=MOD;
	(s[now<<1|1].mul*=s[now].mul)%=MOD;
	((s[now<<1].add*=s[now].mul)+=s[now].add)%=MOD;
	((s[now<<1|1].add*=s[now].mul)+=s[now].add)%=MOD;
	s[now].add=0;s[now].mul=1;
}
void add(int now,int l,int r,int k){
	if(l<=s[now].ls&&s[now].rs<=r){
		(s[now].add+=k)%=MOD;
		(s[now].sum+=s[now].num()*k)%=MOD;
		return;
	}
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)add(now<<1,l,r,k);
	if(r>mid)add(now<<1|1,l,r,k);
	s[now].sum=(s[now<<1].sum+s[now<<1|1].sum)%MOD;
}
void mul(int now,int l,int r,int k){
	if(l<=s[now].ls&&s[now].rs<=r){
		(s[now].mul*=k)%=MOD;
		(s[now].add*=k)%=MOD;
		(s[now].sum*=k)%=MOD;
		return;
	}
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)mul(now<<1,l,r,k);
	if(r>mid)mul(now<<1|1,l,r,k);
	s[now].sum=(s[now<<1].sum+s[now<<1|1].sum)%MOD;
}
int query(int now,int l,int r,int sum=0){
	if(l<=s[now].ls&&s[now].rs<=r)return s[now].sum;
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)sum+=query(now<<1,l,r);
	if(r>mid)sum+=query(now<<1|1,l,r);
	return sum%MOD;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,m,x,y,t;
	cin>>n>>m>>MOD;
	for(i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	while(m--){
		cin>>t>>x>>y;
		if(t==1)cin>>t,mul(1,x,y,t);
		else if(t==2)cin>>t,add(1,x,y,t);
		else cout<<query(1,x,y)<<'\n';
	}
	return 0;
}