#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int n;
inline bool check(int k,int Vasya=0,int Petya=0)
{
	int n=::n;
	while(n)
	{
		if(n<=k){Vasya+=n;break;}
		Vasya+=k;n-=k;
		Petya+=n/10;n-=n/10;
	}
	return Vasya>=Petya;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int ans=-1;
	cin>>n;
	int left=1,right=n,mid;
	while(left<=right)
		if(check(mid=(left+right)>>1))ans=mid,right=mid-1;
		else left=mid+1;
	cout<<ans;
	return 0;
}
