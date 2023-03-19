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
int a[57][57],f[57][57][57][57];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=1;k<=n;k++)for(t=j+1;t<=m;t++)
		f[i][j][k][t]=max(max(f[i-1][j][k-1][t],f[i-1][j][k][t-1]),max(f[i][j-1][k-1][t],f[i][j-1][k][t-1]))+a[i][j]+a[k][t];
	cout<<f[n][m-1][n-1][m];
	
	return 0;
}