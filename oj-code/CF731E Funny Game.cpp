#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
	ans=a[n];
	for(i=n-1;i>=2;i--)ans=max(ans,a[i]-ans);
	cout<<ans;
	
	return 0;
}
