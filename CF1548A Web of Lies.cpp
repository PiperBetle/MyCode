#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define int long long
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[200007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int u,v,ans=0;
	
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		a[min(u,v)]++;
	}
	for(i=1;i<=n;i++)
		if(a[i]==0)
			ans++;
	cin>>m;
	while(m--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>u>>v;
			if(a[min(u,v)]==0)
				ans--;
			a[min(u,v)]++;
		}
		else if(t==2)
		{
			cin>>u>>v;
			a[min(u,v)]--;
			if(a[min(u,v)]==0)
				ans++;
		}
		else cout<<ans<<'\n';
	}
	
    return 0;
}
