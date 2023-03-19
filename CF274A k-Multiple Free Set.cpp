#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define int long long
using std::cin;using std::cout;
std::map<int,bool>b;
int a[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	for(i=1;i<=n;i++)if(!b[a[i]])ans++,b[a[i]*m]=true;
	cout<<ans;
	return 0;
}