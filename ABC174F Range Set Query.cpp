#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=5e5+1;
struct{int l,r,id;}q[kN];
int cnt[kN],a[kN],bl[kN],ans[kN],n,m,blk,num;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;blk=int(__builtin_sqrt(n));
	for(int i=1;i<=n;i++)cin>>a[i],bl[i]=(i%blk==1?++num:num);
	for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r,q[i].id=i;
	std::sort(q+1,q+1+m,[](cauto &x,cauto &y){return bl[x.l]==bl[y.l]?x.r<y.r:bl[x.l]<bl[y.l];});
	for(int i=1,l=1,r=0,now=0;i<=m;i++){
		auto add=[&](int x){if(++cnt[a[x]]==1)now++;};
		auto del=[&](int x){if(--cnt[a[x]]==0)now--;};
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		ans[q[i].id]=now;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}