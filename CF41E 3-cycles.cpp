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
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	cout<<(n/2)*(n/2)+(n%2)*(n/2)<<'\n';
	for(int i=1;i<=n/2;i++)for(int j=n/2+1;j<=n;j++	)
		cout<<i<<' '<<j<<'\n';
	return 0;
}