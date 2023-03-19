#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
long long a[10007],f[10007]={1};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	long long i,j,k;
	long long n,m,v;
	
	cin>>v>>n;
	for(i=1;i<=v;i++)cin>>a[i];
	for(i=1;i<=v;i++)
		for(j=a[i];j<=n;j++)
			f[j]=f[j]+f[j-a[i]];
	cout<<f[n];
	
	return 0;
}
