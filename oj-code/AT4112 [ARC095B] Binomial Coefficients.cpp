#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[100007],n,p=1;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(abs(a[i]*2-a[n])<abs(a[p]*2-a[n]))p=i;
	cout<<a[n]<<' '<<a[p];
	return 0;
}