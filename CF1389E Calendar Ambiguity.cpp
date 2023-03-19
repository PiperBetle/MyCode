#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
#define int long long
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T;cin>>T;while(T--){
		int m,d,w;cin>>m>>d>>w;
		int p=std::min(m,d)-1,g=w/std::gcd(d-1,w);
		cout<<p/g*(p+1)-(1+p/g)*(p/g)/2*g<<'\n';
	}
	return 0;
}