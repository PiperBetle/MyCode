#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int n,a[100007],b[100007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	std::sort(a+1,a+1+n);std::sort(b+1,b+1+n);
	int *a1=&a[1],*a2=&a[n],*b1=&b[1],*b2=&b[n],ans=0;
	for(int i=1;i<=n;i++){
		if(*a1>*b1){a1++;b1++;ans+=2;continue;}
		if(*a1<*b1){a1++;b2--;continue;}
		if(*a2>*b2){a2--;b2--;ans+=2;continue;}
		if(*a1==*b2)ans++;
		a1++;b2--;
	}
	cout<<ans<<' ';
	a1=&b[1],a2=&b[n],b1=&a[1],b2=&a[n],ans=0;
	for(int i=1;i<=n;i++){
		if(*a1>*b1){a1++;b1++;ans+=2;continue;}
		if(*a1<*b1){a1++;b2--;continue;}
		if(*a2>*b2){a2--;b2--;ans+=2;continue;}
		if(*a1==*b2)ans++;
		a1++;b2--;
	}
	cout<<2*n-ans;
	return 0;
}