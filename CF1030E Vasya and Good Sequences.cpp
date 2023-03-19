#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=3e5+1;
int n,a[kN],cnt[]={1,0},sum;
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){loli x;cin>>x;a[i]=__builtin_popcountll(x);}
	for(int l=1;l<=n;l++){
		ans+=cnt[(sum+=a[l])&1]++;
		for(int r=l,max=0,num=0;r<=std::min(n,l+58);r++)
			max=std::max(max,a[r]),
			ans-=(num+=a[r])%2==0&&2*max>num;
	}
	cout<<ans;
	return 0;
}