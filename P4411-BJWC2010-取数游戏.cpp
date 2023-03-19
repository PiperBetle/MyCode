#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int a[50005],last[1000005],f[50005];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int n,m,t,l,ans=-1;
	int i,j,k;
	
	cin>>n>>l;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j*j<=a[i];j++)
		{
			if(a[i]%j)
				continue;
			int x=j,y=a[i]/j;
			if(x>=l)f[i]=max(f[i],f[last[x]]+1);
			if(y>=l)f[i]=max(f[i],f[last[y]]+1);
			last[x]=last[y]=i;
		}
		ans=max(ans,f[i]);
	}
	cout<<ans<<'\n';
	
	return 0;
}