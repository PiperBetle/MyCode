#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[200007],b[200007],s1[200007],s2[200007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,ans=0x3f3f3f3f;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	std::sort(a+1,a+1+n);
	for(int i=2;i<=n;i+=2)s1[i]=s1[i-2]+a[i]-a[i-1];
	for(int i=n-1;i>=1;i-=2)s2[i]=s2[i+2]+a[i+1]-a[i];
	for(int i=1;i<=m;i++){
		int p=std::lower_bound(a+1,a+1+n,b[i])-a;
		if(!(p&1))p--;
		ans=std::min(ans,s1[p-1]+s2[p+1]+abs(a[p]-b[i]));
	}
	cout<<ans;
	return 0;
}