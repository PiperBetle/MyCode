#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[50007],bl[50007],vis[50007],ans[50007];
struct ask{int l,r,id;bool operator<(const ask &t){return bl[l]==bl[t.l]?r<t.r:bl[l]<bl[t.l];}}q[50007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m,k,l=1,r=0;cin>>n>>m>>k;int sz=n/__builtin_sqrt(2*m/3.),num=0;long long now=0;
	for(int i=1;i<=n;i++)cin>>a[i],bl[i]=(i%sz==1?++num:num);
	for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r,q[i].id=i;
	std::sort(q+1,q+1+m);
	for(int i=1;i<=m;i++){
		auto add=[&](const int &x){now+=vis[a[x]]*2+1;vis[a[x]]++;};
		auto del=[&](const int &x){vis[a[x]]--;now-=vis[a[x]]*2+1;};
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		ans[q[i].id]=now;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}