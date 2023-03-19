#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define MOD 1000000007
using namespace std;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int p,ans=1;
	
	cin>>T>>n>>m>>p;
	for(i=n-(m<<1)+2;i<=n-m+1;i++)
		ans=ans*i%p;
	cout<<ans<<'\n';
	
	return 0;
}