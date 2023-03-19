#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
constexpr int MOD=998244353,PHI=MOD-1;
using std::cin;using std::cout;
inline int qp(int a,int b,int t=1){if(!a)return 0;for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,a,b;cin>>n>>m>>a>>b;int h=b-a+1,k=n*m;
	if(k&1)return cout<<qp(h,k%PHI),0;
	if(h&1)return cout<<(qp(h%MOD,k%PHI)+1)*qp(2,MOD-2)%MOD,0;
	return cout<<qp(h%MOD,k%PHI)*qp(2,MOD-2)%MOD,0;
	return 0;
}