#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<numeric>
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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+1,MOD=998244353;
int n,m,a[N],b[N],s1,s2,s3;
inline int qp(int _a,int _b){int t=1;for(;_b;_b>>=1,_a=_a*_a%MOD)if(_b&1)t=_a*t%MOD;return t;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	if(m==0)return cout<<n,0;
	for(int i=1;i<=n;i++)cin>>a[i],s1+=a[i];
	for(int i=1;i<=n;i++)cin>>b[i],s2+=b[i];
	for(int i=1;i<=n;i++)(s3+=a[i]*b[i])%=MOD;
	cout<<((s1%=MOD)*(s2%=MOD)%MOD*qp(s3,m-1)%MOD+MOD)%MOD;
	return 0;
}