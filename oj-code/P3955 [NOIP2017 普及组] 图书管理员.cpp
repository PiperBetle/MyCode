#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,q;
	
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	while(q--)
	{
		cin>>m>>k;
		int MOD=1,flag=0;
		for(j=1;j<=m;j++)MOD*=10;
		for(j=1;j<=n;j++)
			if(a[j]%MOD==k)
			{
				flag=j;
				break;
			}
		if(flag==0)cout<<"-1\n";
		else cout<<a[flag]<<"\n";
	}
	
	return 0;
}
