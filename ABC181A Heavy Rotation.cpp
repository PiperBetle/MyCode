#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n;
	if(n&1)cout<<"Black";
	else cout<<"White";
	return 0;
}