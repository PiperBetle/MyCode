#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	loli x,y;
	cin>>x>>y;
	// cout<<std::__gcd(x,y);
	// loli p=0x3f3f3f3f3f3f;
	// for(int k=0;k<=100000000;k++){
	// 	if(abs(p)>abs(x))p=x;
	// 	x=abs(x-y);
	// }
	// assert(p==std::min(x%y,y-x%y));
	cout<<std::min(x%y,y-x%y);
	return 0;
}
// n == |n-k|