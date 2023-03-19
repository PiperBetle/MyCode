#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int MOD=1e9+7,kN=2e5+1;
constexpr int add0(int x,int y){return (x+=y)<MOD?x:x-MOD;}
template<typename...args>constexpr int add0(int x,args...y){return (x+=add0(y...))<MOD?x:x-MOD;}
constexpr int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
template<typename...args>constexpr int&add1(int&x,args...y){return (x+=add0(y...))<MOD?x:x-=MOD;}
constexpr int sub0(int x,int y){return (x-=y)<0?x+MOD:x;}
template<typename...args>constexpr int sub0(int x,args...y){return (x-=add0(y...))<0?x+MOD:x;}
constexpr int&sub1(int&x,int y){return (x-=y)<0?x+=MOD:x;}
template<typename...args>constexpr int&sub1(int&x,args...y){return (x-=add0(y...))<0?x+=MOD:x;}
constexpr int mul(int x,int y){return int(1ll*x*y%MOD);}
template<typename...args>constexpr int mul(int x,args...y){return int(1ll*x*mul(y...)%MOD);}
constexpr int qp(int a,int b){int t=1;for(;b;b>>=1,a=mul(a,a))if(b&1)t=mul(a,t);return t;}
int fac[kN],ifa[kN];
inline int binum(int x,int y){int ans=ifa[y];for(int i=x-y+1;i<=x;i++)ans=mul(ans,i);return ans;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	fac[0]=fac[1]=ifa[0]=ifa[1]=1;
	for(int i=2;i<kN;i++)fac[i]=mul(fac[i-1],i);
	ifa[kN-1]=qp(fac[kN-1],MOD-2);
	for(int i=kN-2;i>1;i--)ifa[i]=mul(ifa[i+1],i+1);
	int n,a,b;cin>>n>>a>>b;
	cout<<sub0(qp(2,n),1,binum(n,a),binum(n,b));
	return 0;
}