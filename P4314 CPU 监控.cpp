#include<iostream>
#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using std::cin;using std::cout;
using std::max;
struct data{
	int x,y;
	data():x(0),y(-inf){}
	data(int a,int b):x(a),y(b){}
	inline data operator+(const data &n){return {max(-inf,x+n.x),max(y+n.x,n.y)};}
	inline data operator*(const data &n){return {max(x,n.x),max(y,n.y)};}
};
int a[100007],n;
struct stn{data pre_tag,now_tag;int ls,rs,pre_max,now_max;}s[400007];
void spread(int now){
	stn &x=s[now],&l=s[now<<1],&r=s[now<<1|1];
	l.pre_tag=l.pre_tag*(l.now_tag+x.pre_tag);
    l.now_tag=l.now_tag+x.now_tag;
    l.pre_max=max({l.pre_max,l.now_max+x.pre_tag.x,x.pre_tag.y});
    l.now_max=max(l.now_max+x.now_tag.x,x.now_tag.y);
    r.pre_tag=r.pre_tag*(r.now_tag+x.pre_tag);
    r.now_tag=r.now_tag+x.now_tag;
    r.pre_max=max({r.pre_max,r.now_max+x.pre_tag.x,x.pre_tag.y});
    r.now_max=max(r.now_max+x.now_tag.x,x.now_tag.y);
    x.pre_tag=x.now_tag=data();
}
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	s[now].pre_tag=s[now].now_tag=data();
	if(l==r){s[now].pre_max=s[now].now_max=a[l];return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);build(now<<1|1,mid+1,r);
	s[now].pre_max=max(s[now<<1].pre_max,s[now<<1|1].pre_max);
	s[now].now_max=max(s[now<<1].now_max,s[now<<1|1].now_max);
}
void change(int now,int l,int r,data k){
	if(l<=s[now].ls&&s[now].rs<=r){
		s[now].pre_tag=s[now].pre_tag*(s[now].now_tag+k);
		s[now].now_tag=s[now].now_tag+k;
		s[now].pre_max=max({s[now].pre_max,s[now].now_max+k.x,k.y});
		s[now].now_max=max(s[now].now_max+k.x,k.y);return;
	}
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)change(now<<1,l,r,k);
	if(r>mid)change(now<<1|1,l,r,k);
	s[now].pre_max=max(s[now<<1].pre_max,s[now<<1|1].pre_max);
	s[now].now_max=max(s[now<<1].now_max,s[now<<1|1].now_max);
}
int query(int now,int l,int r,bool f,int ans=-inf){
	// cout<<now<<' '<<s[now].ls<<' '<<s[now].rs<<'\n';
	if(l<=s[now].ls&&s[now].rs<=r)return f?s[now].pre_max:s[now].now_max;
	spread(now);int mid=(s[now].ls+s[now].rs)>>1;
	if(l<=mid)ans=max(ans,query(now<<1,l,r,f));
	if(r>mid)ans=max(ans,query(now<<1|1,l,r,f));
	return ans;
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T,i,l,r,k;char c;cin>>n;for(i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);cin>>T;while(T--){
		cin>>c;
		switch(c){
			case 'Q':cin>>l>>r;cout<<query(1,l,r,false)<<'\n';break;
			case 'A':cin>>l>>r;cout<<query(1,l,r,true)<<'\n';break;
			case 'P':cin>>l>>r>>k;change(1,l,r,data(k,-inf));break;
			case 'C':cin>>l>>r>>k;change(1,l,r,data(-inf,k));break;
		}
	}
	return 0;
}