#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int c[1000007],b[1000007],n;
inline bool check(int x)
{
	for(int i=1;i<x;i++)b[i]=c[i];
	std::sort(b+1,b+x);
	int lim=n-x;
	for(int i=1;i<x;i++)
		if(lim++<b[i])return 0;
	return 1;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;

	cin>>n;
	for(i=1;i<=n;i++)cin>>c[i];
	int left=1,right=n,mid;
	while(left<=right)
	{
		mid=left+right>>1;
		if(check(mid))k=mid,left=mid+1;
		else right=mid-1;
	}
	cout<<n-k;
	
	return 0;
}