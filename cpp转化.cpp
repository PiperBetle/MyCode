#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	std::string a,b="";
	while(std::getline(cin,a)){
		cout<<b<<"\"";b=",\n";
		for(char it:a){
			switch(it){
				case '\t':cout<<"\\t";continue;
				case '\"':cout<<"\\\"";continue;
				case '\\':cout<<"\\\\";continue;
				default:cout<<it;
			}
		}
		cout<<"\"";
	}
	return 0;
}