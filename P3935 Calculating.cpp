#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
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
constexpr int MOD=998244353;
int solve(int n){
	int sum=0;
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		(sum+=(r-l+1)*(n/l))%=MOD;
	}
	return sum;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int l,r;cin>>l>>r;
	cout<<(solve(r)+MOD-solve(l-1))%MOD;
	return 0;
}