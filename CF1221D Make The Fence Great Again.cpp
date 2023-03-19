#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
constexpr auto inf=0x3f3f3f3f3f3f3f3f;
int f[300007][3],h[300007],b[300007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T;cin>>T;while(T--){
		int n;cin>>n;
		std::fill(f[1],f[1]+3*n,inf);
		for(int i=1;i<=n;i++)cin>>h[i]>>b[i];
		f[1][0]=0,f[1][1]=b[1],f[1][2]=(b[1]<<1);
		for(int i=2;i<=n;i++)for(int j=0;j<=2;j++)for(int k=0;k<=2;k++)
			if(h[i-1]+j!=h[i]+k)f[i][k]=std::min(f[i][k],f[i-1][j]+b[i]*k);
		cout<<std::min({f[n][0],f[n][1],f[n][2]})<<'\n';
	}
	return 0;
}