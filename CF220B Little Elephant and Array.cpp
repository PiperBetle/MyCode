#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[100007],bl[100007],ans[100007],vis[100007];
struct ask{int l,r,id;bool operator<(const ask &t){return bl[l]==bl[t.l]?r<t.r:bl[l]<bl[t.l];}}q[100007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;int sz=__builtin_sqrt(n),num=0;
	for(int i=1;i<=n;i++)cin>>a[i],bl[i]=(i%sz==1?++num:num);
	for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r,q[i].id=i;
	std::sort(q+1,q+1+m);
	int l=1,r=0,now=0;
	auto add=[&](const int &x){if(a[x]>n)return;vis[a[x]]++;if(vis[a[x]]==a[x])now++;if(vis[a[x]]==a[x]+1)now--;};
	auto del=[&](const int &x){if(a[x]>n)return;if(vis[a[x]]==a[x]+1)now++;if(vis[a[x]]==a[x])now--;vis[a[x]]--;};
	for(int i=1;i<=m;i++){
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		ans[q[i].id]=now;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}