#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
inline int gcd(int _a,int _b)
{
	if(_b==0)return _a;
	return gcd(_b,_a%_b);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		m=(n<<1)+2;
		if(n<1)puts("0");
		else cout<<n/gcd(n,m)<<'/'<<m/gcd(n,m)<<'\n';
	}
	
	return 0;
}
