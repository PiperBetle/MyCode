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
std::priority_queue<int,std::vector<int>,std::greater<>>q;
int n;
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(!q.empty()&&q.top()<x)ans+=x-q.top(),q.pop(),q.push(x);
		q.push(x);
	}
	cout<<ans;
	return 0;
}