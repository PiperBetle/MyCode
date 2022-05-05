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
	std::string a;cin>>a;std::reverse(a.begin(),a.end());
	for(int i=a.length()-1;~i;i--)a[i]-='0',ans+=((a[i]*(a[i]-1)>>1)+a[i]*sum)*pw[i]+a[i]*f[i],sum+=a[i];
	cout<<sum+ans;
	return 0;
}