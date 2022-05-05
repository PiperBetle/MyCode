#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define int long long
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define MOD 1000000007
using namespace std;
inline int gcd(int _a,int _b)
{
	if(_b==0)return _a;
	return gcd(_b,_a%_b);
}
inline int lcm(int _a,int _b)
{
	return _a/gcd(_a,_b)*_b;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int ans;
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		k=1;
		ans=0;
		for(i=2;k<=n;i++)
		{
			ans=(ans+i*(n/k-n/lcm(i,k))%MOD)%MOD;
			k=lcm(i,k);
		}
		cout<<ans<<'\n';
	}
	
    return 0;
}
