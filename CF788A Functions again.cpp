#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int a[1000007],f[1000007][2];
inline int qp(int k){return k&1?-1:1;}
template<typename _Tp>inline _Tp abs(_Tp x){return 0<x?x:-x;}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,ans=-0x3f3f3f3f3f3f3f3f;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],a[i-1]=abs(a[i]-a[i-1]);
	for(i=1;i<=n;i++){
		f[i][0]=std::max(f[i-1][1]+a[i],a[i]);
		f[i][1]=std::max(f[i-1][0]-a[i],0ll);
	}
	for(i=1;i<n;i++)ans=std::max({ans,f[i][0],f[i][1]});
	cout<<ans;
	return 0;
}