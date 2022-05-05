#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
#define int long long
inline int sum(int n){return (1+n)*n>>1;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,x,y,ans=0;
	cin>>n;while(n--){
		cin>>x>>y;
		ans+=sum(y)-sum(x-1);
	}
	cout<<ans;
	return 0;
}