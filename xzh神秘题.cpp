#include<bits/stdc++.h>
#define ll long long
#define ri register
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N=1e5+7;
int n,m,t[N<<2];
bool lzy[N<<2];
struct qjc{int l,r,x;}q[N],a[N];
inline void push_up(int rt){t[rt]=t[rt<<1]+t[rt<<1|1]; }
inline void f(int l,int r,int rt){t[rt]=r-l+1,lzy[rt]=1;}
inline void push_down(int l,int r,int rt){
	if(!lzy[rt])return;
	int mid=(l+r)>>1;
	f(l,mid,rt<<1);
	f(mid+1,r,rt<<1|1);
	lzy[rt]=0;
}
inline void update(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R)return f(l,r,rt);
	push_down(l,r,rt);int mid=(l+r)>>1;
	if(L<=mid)update(L,R,l,mid,rt<<1);
	if(R>mid)update(L,R,mid+1,r,rt<<1|1);
	push_up(rt);
}
inline int query(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R)return t[rt];
	push_down(l,r,rt);int mid=(l+r)>>1,res=0;
	if(L<=mid)res+=query(L,R,l,mid,rt<<1);
	if(R>mid)res+=query(L,R,mid+1,r,rt<<1|1);
	return res;
}
inline bool check(int p){
	memset(t,0,sizeof(t));
	for(int i=1;i<=p;i++)a[i]=q[i];
	sort(a+1,a+p+1,[&](qjc&x,qjc&y){return x.x>y.x;});
	for(int i=1,j=1,l,r,L,R;i<=p;i=++j){
		while(j<=p&&a[j].x==a[i].x)j++;
		j--;
		l=L=a[i].l,r=R=a[i].r;
		for(int k=i+1;k<=j;k++){
			L=min(a[k].l,L),l=max(a[k].l,l);
			R=max(a[k].r,R),r=min(a[k].r,r);
		}
		if(l>r)return 1;
		if(query(l,r,1,n,1)==r-l+1)return 1;
		update(L,R,1,n,1);
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		auto&[l,r,x]=q[i];
		scanf("%d%d%d",&l,&r,&x);
	}
	int l=1,r=m,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
