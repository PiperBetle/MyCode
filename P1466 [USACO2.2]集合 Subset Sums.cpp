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
	if(m&1)
	{
		cout<<0;
		return 0;
	}
	f[0]=1;
	for(i=1;i<=n;i++)
		for(j=m>>1;j>=i;j--)
		{
			f[j]+=f[j-i];
		}
	cout<<(f[m>>1]>>1);
	
    return 0;
}
