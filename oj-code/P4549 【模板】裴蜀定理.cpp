#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int gcd(int _a,int _b)
{
	if(_b==0)return _a;
	return gcd(_b,_a%_b);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans;
	
	cin>>n;
	cin>>ans;
	for(i=2;i<=n;i++)
	{
		cin>>m;
		if(m<0)m=-m;
		ans=gcd(ans,m);
	}
	cout<<ans;
	
    return 0;
}
