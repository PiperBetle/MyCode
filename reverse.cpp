#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using std::cin;using std::cout;
std::vector<std::string>b;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	std::string a;
	while(std::getline(cin,a)){
		b.emplace_back(a);
	}
	while(!b.empty())cout<<b.back()<<'\n',b.pop_back();
	return 0;
}