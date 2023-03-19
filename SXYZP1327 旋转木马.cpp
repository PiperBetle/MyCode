#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int A,B;cin>>A>>B;
	if(A<6)return cout<<0,0;
	if(A<=12)return cout<<B/2,0;
	cout<<B;
	return 0;
}