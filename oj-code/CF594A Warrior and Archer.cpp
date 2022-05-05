#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[200007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,ans=0x3f3f3f3f;
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	for(int i=1;i<=(n>>1);i++)ans=std::min(ans,a[i+(n>>1)]-a[i]);
	cout<<ans;
	return 0;
}