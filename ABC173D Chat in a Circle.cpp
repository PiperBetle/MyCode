#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1;
int n,a[kN];
bool operator<(const pii &x,const pii &y){
	return std::min(x.first,x.second)<std::min(y.first,y.second);
}
std::priority_queue<pii>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n,std::greater<>());
	q.emplace(a[1],a[2]);
	loli ans=a[1];
	for(int i=3;i<=n;i++){
		auto[x,y]=q.top();
		if(q.size()>1)q.pop();
		ans+=std::min(x,y);
		q.emplace(a[i],x);
		q.emplace(a[i],y);
	}
	cout<<ans;
	return 0;
}