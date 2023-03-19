#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) loli((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<loli,loli>;
constexpr loli kN=1e5+1;
loli n,m,k,p,h[kN],a[kN],d[kN];
std::priority_queue<pii,std::vector<pii>,std::greater<>>q;
bool check(loli x){
	std::fill_n(d+1,n,x);
	while(!q.empty())q.pop();
	for(loli i=1;i<=n;i++)if(x-m*a[i]<h[i])q.emplace(x/a[i],i);
	for(loli i=1;i<=m;i++)for(loli j=1;j<=k;j++){
		if(q.empty())return true;
		auto[res,id]=q.top();q.pop();
		if(res<i)return false;
		res=(d[id]+=p)/a[id];
		if(d[id]-m*a[id]<h[id])q.emplace(res,id);
	}
	return q.empty();
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k>>p;
	loli l=0,r=0x3f3f3f3f3f3f3f3f,mid,ans=-1;
	for(loli i=1;i<=n;i++)cin>>h[i]>>a[i],l=std::min(h[i],l);
	while(l<=r)if(check(mid=(l+r)/2))ans=mid,r=mid-1;else l=mid+1;
	cout<<ans;
	return 0;
}