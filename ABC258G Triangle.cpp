#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<bitset>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=3001;
bool a[kN][kN];
std::bitset<kN>f[kN];
int n;
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		char c;cin>>c;
		a[i][j]=(c=='1');
		if(i<j)f[i][j]=a[i][j];
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		if(a[i][j])ans+=(f[i]&f[j]).count();
	cout<<ans;
	return 0;
}