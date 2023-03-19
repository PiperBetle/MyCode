#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using namespace std;
int a[100007],f[100007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=0,t;

	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		a[t]++;
		m=max(m,t);
	}
	f[1]=a[1];
	for(i=2;i<=m;i++)
		f[i]=max(f[i-1],f[i-2]+a[i]*i);
	cout<<f[m]<<'\n';
	
	return 0;
}