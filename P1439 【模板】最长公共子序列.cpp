#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1000007],b[1000007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	 
	cin>>n;
	memset(b,0x3f,sizeof b);
	for(i=1;i<=n;i++)
	{
		cin>>t;
		a[t]=i;
	}
	for(i=1;i<=n;i++)
	{
		cin>>t;
		t=a[t];
		*lower_bound(b+1,b+n+1,t)=t;
	}
	cout<<lower_bound(b+1,b+n+1,b[0])-b-1;
	
	return 0;
}
