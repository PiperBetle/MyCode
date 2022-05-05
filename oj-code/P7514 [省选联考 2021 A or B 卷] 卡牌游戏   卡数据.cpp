#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[1000007],b[1000007];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	int maxn=-1e9,minn=1e9;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		maxn=max(maxn,min(a[i],b[i]));
		minn=min(minn,max(a[i],b[i]));
	}
	cout<<max(maxn,minn)-min(maxn,minn);
	
    return 0;
}
