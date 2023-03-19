#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int a[2000007],f[2000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>k>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(i=1;i<=n;i++)
		for(j=a[i];j<=2000000;j++)
			if(f[j-a[i]]<k)
				f[j]=min(f[j],f[j-a[i]]+1);
	for(i=1;i<=2000000;i++)
		if(f[i]==f[2000006])
		{
			cout<<i-1;
			return 0;
		}
	cout<<0;
	
    return 0;
}
