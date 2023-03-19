#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int f[10000007],b[10000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int a,cnt=0;
	
	cin>>a>>n>>m;
	f[1]=1;
	for(i=2;i<=n;i++)
	{
		f[i]=m+f[i-1];
		while(f[i]>i)
			f[i]-=i;
	}
	for(i=a;i<=n;i++)
		b[f[i]]++;
	for(i=0;i<10000007;i++)
		cnt=max(cnt,b[i]);
	cout<<cnt<<'\n';
	for(i=0;i<10000007;i++)
		if(b[i]==cnt)
			cout<<i<<' ';
	
	return 0;
}