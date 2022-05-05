#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,a,b;
	cin>>a>>b;
	int n=sqrt((a+b)<<1);
	if(n*(n+1)!=((a+b)<<1))return cout<<"No",0;
	cout<<n;
	for(i=n;i>=1;i--)if(a>=i)cout<<' '<<i,a-=i;
	return 0;
}