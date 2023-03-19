#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
using lolo=long long;
using i128=__int128_t;
using pii=std::pair<int,int>;
std::vector<std::string>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		s.emplace_back(n,'.');
		for(int j=0;j<3;j++)s.back()[(3*i+j)%n]='#';
	}
	if(n%3)std::swap(s[0],s[n/3-1]),std::swap(s[n-n/3],s[n-1]);
	for(const auto &it:s)cout<<it<<'\n';
	return 0;
}