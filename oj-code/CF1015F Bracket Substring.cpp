#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
using std::cin;using std::cout;
constexpr auto MOD=1000000007;
std::string a;
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
int f[4007][4007];
signed main(){
//	freopen("brackets.in","r",stdin);
//	freopen("brackets.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m=0x3f3f3f3f3f3f3f3f,ans=0,k=0;
	for(cin>>n>>a;char c:a)m=std::min(m,c=='('?++k:--k);
	m=-m;n=(n<<1)-a.length();f[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<=i;j++)f[i][j]=(f[i-1][j+1]+(j?f[i-1][j-1]:0))%MOD;
	for(int i=0;i<=n;i++)for(int j=m;j<=i;j++)ans=(ans+f[i][j]*f[n-i][j+k])%MOD;
	cout<<ans;
	return 0;
}