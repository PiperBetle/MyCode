#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<bitset>
#define int unsigned
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
constexpr int N=100000001;
std::bitset<N>vis;
int n,A,B,C,D,ans;
inline bool check(int x){return x%2==0||x%3==0||x%5==0;}
void sieve(int x){
	int v=A*x*x*x+B*x*x+C*x+D;
	for(uloli i=x;i<=n;i*=x)ans+=n/i*v;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>A>>B>>C>>D;
	if(n>=2)sieve(2);
	if(n>=3)sieve(3);
	if(n>=5)sieve(5);
	for(int i=7;i<=n;i++){
		if(check(i)||vis[i/3])continue;else sieve(i);
		for(int j=i*2;j<=n;j+=i)if(!check(j))vis[j/3]=true;
	}
	cout<<ans;
	return 0;
}