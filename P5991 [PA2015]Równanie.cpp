#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
int k,a,b,ans;
constexpr int sqr(int x){return x*x;}
int calc(venti x){
	int cnt=0;
	for(venti i=x;i;i/=10)cnt+=sqr(int(i%10));
	return cnt;
}
signed main(){
//	freopen("coffin.in","r",stdin);
//	freopen("coffin.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>k>>a>>b;
	for(venti i=0;i<=18*81;i++)
		if(a<=k*i&&k*i<=b&&i==calc(k*i))ans++;
	cout<<ans;
	return 0;
}