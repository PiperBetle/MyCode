#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int f[2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	m=n*(n+1)>>1;
	if(m&1)return cout<<0,0;
	f[0]=1;m>>=1;
	for(i=1;i<=n;i++)
		for(j=m;j>=i;j--)
			f[j]+=f[j-i];
	cout<<(f[m]>>1);
	
    return 0;
}