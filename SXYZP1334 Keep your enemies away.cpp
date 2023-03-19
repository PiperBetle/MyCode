#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int h,n,t;cin>>h>>n;
	while(n--)cin>>t,h-=t;
	cout<<(h>0?"No":"Yes");
	return 0;
}