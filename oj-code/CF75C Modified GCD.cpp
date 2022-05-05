#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
std::vector<int>a;
inline int gcd(int a, int b)
{
	if(!a)return b;
	if(!b)return a;
	int t=__builtin_ctz(a|b);
	a>>=__builtin_ctz(a);
	do
	{
		b>>=__builtin_ctz(b);
		if(a>b)std::swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,T,l,r,p;
	cin>>n>>m>>T;
	int g=gcd(n,m);
	for(i=1;i*i<=g;i++)if(g%i==0)a.emplace_back(i),a.emplace_back(g/i);
	std::sort(a.begin(),a.end());
	while(T--)
		cin>>l>>r,
		p=a[std::upper_bound(a.begin(),a.end(),r)-a.begin()-1],
		cout<<(p<l?-1:p)<<'\n';
	return 0;
}
