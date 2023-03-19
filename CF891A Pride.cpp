#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
int a[2007],g[2007][2007];
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
	int i,j,n,cnt=0,g=0,ans=0x3f3f3f3f;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],g=gcd(g,a[i]),cnt+=(a[i]==1);
	if(cnt)return cout<<n-cnt,0;
	if(g!=1)return cout<<"-1",0;
	for(i=1;i<n;i++)for(g=a[i],j=i+1;j<=n;j++)
	{
		g=gcd(g,a[j]);
		if(g==1){ans=std::min(ans,j-i);break;}
	}
	cout<<ans+n-1;
	return 0;
}