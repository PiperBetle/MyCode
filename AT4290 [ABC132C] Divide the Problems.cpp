#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr int kN=1e5+1;
int n,a[kN];
signed main(){
//	freopen("sequ.in","r",stdin);
//	freopen("sequ.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	cout<<a[n/2+1]-a[n/2];
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}