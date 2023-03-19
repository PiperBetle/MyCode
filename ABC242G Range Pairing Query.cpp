#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
constexpr int kN=1e5+1,kM=1e6+1;
int n,m,a[kN],bl[kN],blk,num,ans[kM],cnt[kN];
struct ask{int l,r,id;bool operator<(const ask&t){return bl[l]==bl[t.l]?r<t.r:bl[l]<bl[t.l];}}q[kM];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;blk=(int)__builtin_sqrt(n);
	for(int i=1;i<=n;i++){cin>>a[i];bl[i]=(i%blk==1?++num:num);}
	cin>>m;for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r,q[i].id=i;
	std::sort(q+1,q+1+m);
	for(int i=1,l=1,r=0,now=0;i<=m;i++){
		auto add=[&](int x){now-=cnt[a[x]]/2;cnt[a[x]]++;now+=cnt[a[x]]/2;};
		auto del=[&](int x){now-=cnt[a[x]]/2;cnt[a[x]]--;now+=cnt[a[x]]/2;};
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		ans[q[i].id]=now;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}