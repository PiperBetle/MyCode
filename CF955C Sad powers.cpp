#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr loli N=1e6,M=N*N*N;
std::basic_string<loli>b;
inline auto sqr(auto x){return x*x;}
inline loli sqrt(loli x){return loli(sqrtl(x));}
inline loli solve(loli x){
	auto p=std::lower_bound(all(b),x);
	if(p==b.end()||*p>x)--p;
	return loli(p-b.begin())+1+sqrt(x);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(loli i=2;i<=N;i++)for(loli k=i*i;k<=M/i;)if(k*=i,sqr(sqrt(k))!=k)b+=k;
	std::sort(all(b));b.erase(std::unique(all(b)),b.end());
	int q;cin>>q;for(loli l,r;q--;)cin>>l>>r,cout<<solve(r)-solve(l-1)<<'\n';
	return 0;
}