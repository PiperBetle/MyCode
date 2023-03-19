#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int p[107],c[107],f[55007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=1e9;
	
	memset(f,0x3f,sizeof f);
	cin>>n>>m;
	f[0]=0;
	for(i=1;i<=n;i++)cin>>p[i]>>c[i];
	for(i=1;i<=n;i++)
		for(j=p[i];j<=m+5000;j++)
			f[j]=min(f[j],f[j-p[i]]+c[i]);
	for(i=m;i<=m+5000;i++)
		ans=min(ans,f[i]);
	cout<<ans;
	
	return 0;
}
