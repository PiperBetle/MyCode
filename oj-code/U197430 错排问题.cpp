#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int f[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	f[1]=0;
	f[2]=1;
	f[3]=2;//312 231
	for(i=4;i<=n;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	cout<<f[n];
	
    return 0;
}
