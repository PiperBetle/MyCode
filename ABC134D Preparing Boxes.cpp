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
constexpr int kN=2e5+1;
int n,a[kN],b[kN];
std::basic_string<int>ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		int sum=0;
		for(int j=i*2;j<=n;j+=i)sum+=b[j];
		if(a[i]!=sum%2)b[i]=1,ans+=i;
	}
	cout<<siz(ans)<<'\n';
	for(int i:ans)cout<<i<<' ';
	return 0;
}