#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
std::string s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>s;
	std::sort(s.begin(),s.end());
	cout<<s;
	return 0;
}