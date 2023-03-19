#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int x,y,A;cin>>x>>y>>A;
	for(int i=1;i<=10;i++){
		A=A*x-y;
		cout<<A<<'\n';
	}
	return 0;
}