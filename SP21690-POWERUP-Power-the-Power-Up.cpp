#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define mod 1000000007
using namespace std;
int qp(int n,int p,int k)//正确保证
{
	if(!p)return 1;
	int t=qp(n,p>>1,k)%k;
	t=(t*t)%k;
	if(p&1)t=(t*n)%k;
	return t;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int a,b,c;
	
	while(scanf("%lld%lld%lld",&a,&b,&c))
	{
		if(a==-1&&b==-1&&c==-1)
			return 0;
		if(a%mod==0)
		{
			if(b==0&&c!=0)
				puts("1");
			else
				puts("0");
			continue;
		}
		t=qp(b,c,mod-1);
		printf("%lld\n",qp(a,t+mod-1,mod));
	}
	
	return 0;
}