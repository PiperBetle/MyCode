#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
using lolo=long long;
using i128=__int128_t;
using pii=std::pair<int,int>;
int n;
std::string s,a,b;
inline bool check(char _c1,char _c2,char _c3){
	std::string _s{_c1,_c2,_c3};
	return _s=="ABC"||_s=="BCA"||_s=="CAB";
}
signed main(){
//	freopen(".in","r",swtdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;s.reserve(n);
	cin>>s;
	for(int i=0;i<siz(s);i++){
		a+=s[i];
		if(siz(a)>2&&check(a[siz(a)-3],a[siz(a)-2],a[siz(a)-1]))a.resize(siz(a)-3);
	}
	cin>>s;
	for(int i=0;i<siz(s);i++){
		b+=s[i];
		if(siz(b)>2&&check(b[siz(b)-3],b[siz(b)-2],b[siz(b)-1]))b.resize(siz(b)-3);
	}
	cout<<(a==b?"YES":"NO");
	return 0;
}