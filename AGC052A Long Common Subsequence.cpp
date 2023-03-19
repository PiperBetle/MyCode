#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
int T,n;
std::string s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	s.reserve(10000);
	cin>>T;while(T--){
		cin>>n>>s>>s>>s;
		for(int i=1;i<=n;i++)cout<<'0';
		for(int i=1;i<=n;i++)cout<<'1';
		cout<<'0'<<'\n';
	}
	return 0;
}