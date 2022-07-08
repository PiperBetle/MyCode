#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
int n,m,ans;
std::priority_queue<int>q;
pii a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	std::sort(a+1,a+1+n);
	pii *p=&a[1];
	for(int i=1;i<=m;i++){
		for(;p<=a+n&&p->first<=i;p++)q.emplace(p->second);
		if(!q.empty())ans+=q.top(),q.pop();
	}
	cout<<ans;
	return 0;
}