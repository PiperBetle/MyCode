#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ext/pb_ds/priority_queue.hpp>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
struct:__gnu_pbds::priority_queue<int>{loli sum;}q[kN];
int n,m,fa[kN],c[kN],l[kN];
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>fa[i]>>c[i]>>l[i];
	for(int i=n;i>=1;i--){
		q[i].push(c[i]);q[i].sum+=c[i];
		while(q[i].sum>m)q[i].sum-=q[i].top(),q[i].pop();
		ans=std::max(ans,1ll*siz(q[i])*l[i]);
		q[fa[i]].sum+=q[i].sum;q[fa[i]].join(q[i]);
	}
	cout<<ans;
	return 0;
}