#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	for(int t=1;t<=n;t=(t<<1)+1+(t&1))
		if(n==t||n==t+1)return putchar('1'),0;
	putchar('0');
	return 0;
}