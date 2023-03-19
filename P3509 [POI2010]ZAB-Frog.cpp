#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
constexpr int N=1e6+1;
int n,k,b[N],f[2][N];
loli a[N],m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=i;
	int l=1,r=l+k;f[0][l]=r;
	for(int i=2;i<=n;i++){
		while(r<n&&a[i]-a[l]>a[r+1]-a[i])l++,r++;
		f[0][i]=(a[i]-a[l]>=a[r]-a[i]?l:r);
	}
	for(int p=0;m;m>>=1,p^=1){
		if(m&1)for(int i=1;i<=n;i++)b[i]=f[p][b[i]];
		for(int i=1;i<=n;i++)f[p^1][i]=f[p][f[p][i]];
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	return 0;
}