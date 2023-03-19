#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
inline void exgcd(int a,int b,int &x,int &y)
{
	if(b==0){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int a[1000007],b[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=1,Mi;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		m*=a[i];
	}
	int ans=0,x,y;
	for(i=1;i<=n;i++)
	{
		Mi=m/a[i];
		exgcd(Mi,a[i],x,y);
		ans=((ans+Mi*x*b[i])%m+m)%m;
	}
	cout<<(ans+m)%m<<'\n';
	
	return 0;
}