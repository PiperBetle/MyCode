#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
using std::cin;using std::cout;
int pw[20],f[20],sum,ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=pw[0]=1;i<=15;i++)pw[i]=10*pw[i-1],f[i]=f[i-1]*10+(pw[i-1]*45);
	std::string a;cin>>a;
	for(int i=0;i<int(a.length());i++){
		int t=a[i]-'0';sum+=t;

	}
	return 0;
}