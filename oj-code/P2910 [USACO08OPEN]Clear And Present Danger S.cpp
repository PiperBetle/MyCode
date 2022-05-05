#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
long long a[207][207],To[10007]={0};
int main()
{
	std::ios::sync_with_stdio(false);
	long long i,j,k;
	long long n,m,ans=0;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>To[i];
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)cin>>a[i][j];
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for(i=1;i<m;i++)ans+=a[To[i]][To[i+1]];
	cout<<ans;
	
	return 0;
}
