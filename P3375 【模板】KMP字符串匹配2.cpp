#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cin;using std::cout;
constexpr int kN=1e6;
std::string a,b;
int kmp[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	a.reserve(kN+1);b.reserve(kN+1);
	cin>>a>>b;a="~"+a;b="~"+b;
	for(size_t i=2,j=0;i<b.size();i++){
		while(j&&b[i]!=b[j+1])j=kmp[j];
		if(b[i]==b[j+1])j++;
		kmp[i]=j;
	}
	for(size_t i=1,j=0;i<a.size();i++){
		if(a[i]==b[j+1])j++;
		if(j+1==b.size()){
			cout<<i-j+1<<'\n';
			j=kmp[j];
		}
		while(j&&a[i+1]!=b[j+1])j=kmp[j];
	}
	for(size_t i=1;i<b.size();i++)cout<<kmp[i]<<' ';
	return 0;
}