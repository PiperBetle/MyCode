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
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int x;cin>>x;
	cout<<x/500*1000+x%500/5*5;
	return 0;
}