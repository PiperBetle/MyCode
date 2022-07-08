#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
constexpr int kN=31;
std::map<int,int>a;
int n,m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t,c;cin>>t;
		while(t--)cin>>c,a[c]++;
	}
	int ans=0;
	for(auto it:a)if(it.second==n)ans++;
	cout<<ans;
	return 0;
}