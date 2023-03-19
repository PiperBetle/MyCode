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
	int i,j,k;
	int n,m,T;

	cin>>T;
	while(T--)
	{
		cin>>n;
		int ans=1;
		for(i=3;i<=(n<<1);i++)
			ans=(ans*i)%MOD;
		cout<<ans<<'\n';
	}
	
	return 0;
}