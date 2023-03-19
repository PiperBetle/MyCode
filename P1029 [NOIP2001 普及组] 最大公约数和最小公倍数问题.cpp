#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long gcd(long long a,long long b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	long long i,j,k;
	long long n,m,t;
	long long x,y,ans=0;
	
	cin>>m>>n;
	if(m==n)ans--;
	n*=m;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0&&gcd(i,n/i)==m)ans+=2;
	}
	cout<<ans;
	
	return 0;
}
