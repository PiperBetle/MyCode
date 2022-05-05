#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 9999991
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int qp(int a,int p,int t=1){for(;p;p>>=1,a=a*a%MOD)if(p&1)t=t*a%MOD;return t;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans;
	
	cin>>n;
	ans=qp(n,n-2);
	for(i=1;i<n;i++)ans=ans*i%MOD;
	cout<<ans;
	
	return 0;
}
