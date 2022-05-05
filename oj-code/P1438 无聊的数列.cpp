#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
struct stn{
	int sum,tag;
	friend stn operator+(const stn &x,const stn &y){return stn{x.sum+y.sum,0};}
}s[400007];
int a[100007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n-1;i>0;i--)a[i+1]=a[i+1]-a[i];
	return 0;
}