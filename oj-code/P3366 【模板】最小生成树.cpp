#include <bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	long long n,T,m;
	long long i,j,k;
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		m=(n<<1)+2;
		if(n==0)puts("0");
		else cout<<n/__gcd(n,m)<<'/'<<m/__gcd(n,m)<<'\n';
	}
	
	return 0;
}

