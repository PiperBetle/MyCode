#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
std::string a;
int n;
struct stn{int ls,rs,d[7];}s[400007];
void push_up(int now){
	stn &r=s[now],&x=s[now<<1],&y=s[now<<1|1];
	r.d[1]=x.d[1]+y.d[1];
	r.d[2]=x.d[2]+y.d[2];
	r.d[3]=x.d[3]+y.d[3];
	r.d[4]=std::min(x.d[1]+y.d[4],x.d[4]+y.d[2]);
	r.d[5]=std::min(x.d[2]+y.d[5],x.d[5]+y.d[3]);
	r.d[6]=std::min({x.d[1]+y.d[6],x.d[4]+y.d[5],x.d[6]+y.d[3]});
}
void build(int now,int l,int r){
	s[now].ls=l,s[now].rs=r;
	if(l==r){s[now].d[a[l]-96]=1;return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	push_up(now);
}
void change(int now,int pos,char k){
	if(s[now].ls==pos&&s[now].rs==pos){
		s[now].d[1]=s[now].d[2]=s[now].d[3]=0;
		s[now].d[k-96]=1;return;
	}
	int mid=(s[now].ls+s[now].rs)>>1;
	if(pos<=mid)change(now<<1,pos,k);
	if(pos>mid)change(now<<1|1,pos,k);
	push_up(now);
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int m,pos;char k;
	cin>>n>>m>>a;
	a=' '+a;
	build(1,1,n);
	while(m--){
		cin>>pos>>k;
		change(1,pos,k);
		cout<<s[1].d[6]<<'\n';
	}
	return 0;
}