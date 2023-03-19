#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e6;
int n,m,f[7];
loli dp[kN+1];
void updata(int c,loli w){for(int i=kN-1;i>=c;i--)dp[i]=std::max(dp[i-c]+w,dp[i]);}
signed main(){
//	freopen("baka.in","r",stdin);
//	freopen("baka.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;(--n)*=3;
	for(int i=1;i<=6;i++)cin>>f[i];
	for(int i=0;i<kN;i++)
		for(int j=1,x=i;x;j++,x/=10)
			if(!(x%10%3))dp[i]+=1ll*f[j]*(x%10/3);
	for(int i=1,t=3;i<=6;i++,t*=10){
		int c=std::min(n,kN/t+1);
		for(int j=0;(1<<j)<c;c-=(1<<j++))updata(t<<j,1ll*f[i]<<j);
		updata(t*c,1ll*f[i]*c);
	}
	cin>>m;for(int x;m--;)cin>>x,cout<<dp[x]<<'\n';
	return 0;
}