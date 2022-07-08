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
constexpr int kN=201,kM=5155;
int n,m,f[kN][kM],ans;
pii a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		loli x;cin>>x;
		while(x%2==0)a[i].first++,x/=2;
		while(x%5==0)a[i].second++,x/=5;
	}
	memset(f,-0x3f,sizeof f);f[0][0]=0;
	for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)for(int k=kM-1;k>=a[i].second;k--)
		f[j][k]=std::max(f[j][k],f[j-1][k-a[i].second]+a[i].first);
	for(int i=0;i<kM;i++)ans=std::max(ans,std::min(i,f[m][i]));
	cout<<ans;
	return 0;
}