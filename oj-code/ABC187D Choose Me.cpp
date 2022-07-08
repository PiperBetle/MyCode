#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int kN=2e5+1;
int n,m,a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x,y;i<=n;i++)
		cin>>x>>y,a[i]=2*x+y,m-=x;
	std::sort(a+1,a+1+n,std::greater<>());
	for(int i=1;i<=n;i++)if((m+=a[i])>0)return cout<<i,0;
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}