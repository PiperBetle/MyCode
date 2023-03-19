#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+2,M=1e5;
int n,q;
std::basic_string<int>p[kN];
struct node{
	int sum=0;node *ls=nullptr,*rs=nullptr;
	void push_up(){sum=0;if(ls)sum+=ls->sum;if(rs)sum+=rs->sum;}
}*rt[kN];
#define mid ((l+r)>>1)
void build(node *&now,int l,int r){
	if(!now)now=new node;
	if(l==r)return;
	build(now->ls,l,mid);
	build(now->rs,mid+1,r);
}
void change(node *&now,int l,int r,int x){
	now=new node(*now);
	if(l==r){now->sum++;return;}
	x<=mid?change(now->ls,l,mid,x):change(now->rs,mid+1,r,x);
	now->push_up();
}
int query(node *now,int l,int r,int x,int y){
	if(!now)return 0;
	if(x<=l&&r<=y)return now->sum;
	if(y<=mid)return query(now->ls,l,mid,x,y);
	if(x>mid)return query(now->rs,mid+1,r,x,y);
	return query(now->ls,l,mid,x,y)+query(now->rs,mid+1,r,x,y);
}
int check(int x,int y,int d){
	int l=std::max(1,x-d),r=std::min(2*M+1,x+d);
	int dw=std::max(1,y-d),up=std::min(2*M+1,y+d);
	return query(rt[r],1,2*M+1,dw,up)-query(rt[l-1],1,2*M+1,dw,up);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x,y;i<=n;i++)cin>>x>>y,p[x+y+1]+=x-y+M+1;
	build(rt[0],1,2*M+1);
	for(int i=1;i<=2*M+1;i++){
		rt[i]=rt[i-1];
		for(int x:p[i])change(rt[i],1,2*M+1,x);
	}
	cin>>q;for(int x,y,k,l,r;q--;){
		cin>>x>>y>>k;l=0,r=2*M+1;
		while(l<r){
			if(check(x+y+1,x-y+M+1,mid)<k)l=mid+1;
			else r=mid;
		}
		cout<<l<<'\n';
	}
	return 0;
}