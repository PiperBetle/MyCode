#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int phi(int n){
	int ans=n;
	for(int i=2;i*i<=n;i++)if(n%i==0){
		ans=ans/i*(i-1);
		while(n%i==0)n/=i;
	}
	if(n>1)ans=ans/n*(n-1);
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,ans=0;cin>>n;
	for(int i=1;i*i<=n;i++)if(n%i==0){
		ans+=i*phi(n/i);
		if(i*i!=n)ans+=n/i*phi(i);
	}
	cout<<ans;
	return 0;
}