#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
#define int long long
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
std::unordered_map<int,int>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m,sum=0,ans=0;cin>>n>>m;
	s[0]++;
	for(int i=1,t;i<=n;i++)cin>>t,s[(sum+=t)%=m]++;
	for(auto it:s)ans+=it.second*(it.second-1)/2;
	cout<<ans;
	return 0;
}