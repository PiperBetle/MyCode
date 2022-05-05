#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
std::string a,s[4];
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n;
	cin>>a;
	n=a.length();
	if(a[n-1]=='4')return a.pop_back(),cout<<a<<"1\n"<<a<<"2\n"<<a<<'3',0;
	for(i=1;i<n;i++)
		if(a[i]=='1')s[1]=a.substr(0,i)+"4\n";
		else if(a[i]=='2')s[2]=a.substr(0,i)+"4\n";
		else if(a[i]=='3')s[3]=a.substr(0,i)+"4\n";
	std::sort(s+1,s+4);
	for(i=1;i<=3;i++)cout<<s[i];
	return 0;
}