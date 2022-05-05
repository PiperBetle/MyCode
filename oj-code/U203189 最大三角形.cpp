#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
char a[2007][2007];
int f[2007][2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0;

	cin>>n;
	for(i=1;i<=n;i++)for(j=i;j<=2*n-i;j++)cin>>a[i][j];
	for(j=1;j<=2*n-1;j++)if(a[1][j]=='-')ans=max(ans,f[1][j]=1);
	for(i=2;i<=n;i++)for(j=i;j<=2*n-i;j++)
		if(a[i][j]=='-')ans=max(ans,f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i-1][j+1]))+1);
	cout<<ans*ans;

	return 0;
}