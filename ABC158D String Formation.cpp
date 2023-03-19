#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<deque>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	std::deque<char>s1,s2;
	std::string a;cin>>a;
	for(char c:a)s1.emplace_back(c),s2.emplace_front(c);
	int q;cin>>q;for(int t;q--;){
		cin>>t;
		if(t==1){swap(s1,s2);continue;}
		char c;cin>>t>>c;
		if(t==2)s1.emplace_back(c),s2.emplace_front(c);
		else s1.emplace_front(c),s2.emplace_back(c);
	}
	for(char c:s1)cout<<c;
	return 0;
}