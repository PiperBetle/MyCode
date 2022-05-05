#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#define int long long
using std::cin;using std::cout;
std::vector<int>pt;
constexpr int MOD=998244353;
int fac[1007]={1,1},inv[1007]={1,1};
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
inline int calc(int x){
	int res=1,sum=0;
	for(auto it:pt){
		int cnt=0;
		while(x%it==0){cnt++;x/=it;}
		res=(res*inv[cnt])%MOD;
		sum+=cnt;
	}
	return res*fac[sum]%MOD;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int d,q;cin>>d>>q;
	for(int i=2;i*i<=d;i++)
		if(d%i==0){while(d%i==0)d/=i;pt.emplace_back(i);}
	if(d>1)pt.emplace_back(d);
	for(int i=2;i<=1000;i++)fac[i]=fac[i-1]*i%MOD;
	inv[1000]=qp(fac[1000],MOD-2);
	for(int i=999;i>=2;i--)inv[i]=inv[i+1]*(i+1)%MOD;
	while(q--){
		int x,y;cin>>x>>y;
		int g=std::gcd(x,y);
		cout<<calc(x/g)*calc(y/g)%MOD<<'\n';
	}
	return 0;
}