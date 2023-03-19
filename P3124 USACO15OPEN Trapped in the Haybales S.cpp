#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
struct point{int data,pos;bool operator<(const point&n){return pos<n.pos;}}a[100007];
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,ans=0x3f3f3f3f3f3f3f3f,d;
	point *l,*r,*p;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i].data>>a[i].pos;
	std::sort(a+1,a+1+n);
	p=std::lower_bound(a+1,a+1+n,point{0,m});
	l=p-1;r=p;d=r->pos-l->pos;
	while(a+1<=l&&r<=a+n)
		if(l->data>=d&&r->data>=d)return cout<<0,0;
		else if(r->data<d)d+=(r+1)->pos-r->pos,r++;
		else if(l->data<d)ans=std::min(d-l->data,ans),d+=l->pos-(l-1)->pos,l--;
	l=p-1;r=p;d=r->pos-l->pos;
	while(a+1<=l&&r<=a+n)
		if(l->data>=d&&r->data>=d)return cout<<0,0;
		else if(l->data<d)d+=l->pos-(l-1)->pos,l--;
		else if(r->data<d)ans=std::min(d-r->data,ans),d+=(r+1)->pos-r->pos,r++;
	cout<<(ans==0x3f3f3f3f3f3f3f3f?-1:ans);
	return 0;
}