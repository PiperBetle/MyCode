#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
signed main(){
//	freopen("e.in","r",stdin);
//	freopen("e.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	cout<<2*n*n<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++)cout<<j<<'\n';
		for(int j=0;j<n;j++)cout<<0<<'\n';
	}
	return 0;
}