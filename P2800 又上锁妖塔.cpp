#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1000007],f[1000007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	memset(f,0x3f,sizeof f);
	f[0]=0;
	f[1]=a[1];
	f[2]=min(f[0],f[1])+a[2];
	for(i=3;i<=n+1;i++)
		f[i]=min(f[i-1],min(f[i-2],f[i-3]))+a[i];
	cout<<f[n+1];
		
	return 0;
}
