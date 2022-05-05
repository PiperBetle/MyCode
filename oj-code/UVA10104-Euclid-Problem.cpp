#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
inline void exgcd(int a,int b,int &x,int &y)
{
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=x*(a/b);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int x,y;
	
	while(~scanf("%lld%lld",&n,&m))
	{
		exgcd(n,m,x,y);
		printf("%lld %lld %lld\n",x,y,n*x+m*y);
	}
	
	return 0;
}