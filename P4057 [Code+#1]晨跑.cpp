#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline long long gcd(long long _a,long long _b);
inline long long lcm(long long _a,long long _b);
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	long long i,j,k;
	
	cin>>i>>j>>k;
	cout<<lcm(lcm(i,j),k);
	
	return 0;
}
inline long long gcd(long long _a,long long _b)
{
    while(_b^=_a^=_b^=_a%=_b);
    return _a;
}
inline long long lcm(long long _a,long long _b)
{
	return _a/gcd(_a,_b)*_b;
}
