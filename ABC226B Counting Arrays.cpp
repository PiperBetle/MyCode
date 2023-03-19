#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_set>
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr int kN=2e5+1,BS=1e9+7;
int n,T,a[kN];
std::unordered_set<unsigned long long>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		unsigned long long h=0;
		for(int i=1;i<=n;i++)(h*=BS)+=a[i]+1;
		s.insert(h);
	}
	cout<<siz(s);
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}