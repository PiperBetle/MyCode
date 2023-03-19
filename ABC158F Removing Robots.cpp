#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<stack>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1,MOD=998244353;
int n,f[kN+1];
pii a[kN];// x d
std::stack<pii>s;
constexpr int add0(int x,int y){return (x+=y)<MOD?x:x-MOD;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	std::sort(a+1,a+1+n);
	f[n+1]=1;
	for(int i=n;i>=1;i--){
		int v=a[i].first+a[i].second,nxt=i+1;
		for(;!s.empty()&&v>a[s.top().first].first;s.pop())nxt=s.top().second;
		s.emplace(i,nxt);f[i]=add0(f[i+1],f[nxt]);
	}
	cout<<f[1];
	return 0;
}