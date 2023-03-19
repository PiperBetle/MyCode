#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
using pll=std::pair<loli,loli>;
std::priority_queue<pll,std::vector<pll>,std::greater<>>q;
loli n,k,ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(loli w;n--;)cin>>w,q.emplace(w,1);
	while((siz(q)-1)%(k-1))q.emplace(0,1);
	while(siz(q)>=k){
		loli w=0,h=0;
		for(int i=1;i<=k;i++){
			w+=q.top().first;
			h=std::max(h,q.top().second);
			q.pop();
		}
		ans+=w;
		q.emplace(w,h+1);
	}
	cout<<ans<<'\n'<<q.top().second-1;
	return 0;
}