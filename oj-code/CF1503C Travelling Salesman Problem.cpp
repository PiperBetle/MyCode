#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
struct city{int h,c;bool operator<(const city &t){return h<t.h;}}a[100007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,p=0,ans=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].h>>a[i].c,ans+=a[i].c;
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		p=std::max(p,a[i].h+a[i].c);
		if(p<a[i+1].h)ans+=a[i+1].h-p;
	}
	cout<<ans;
	return 0;
}