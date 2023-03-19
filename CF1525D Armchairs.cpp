#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int a[5007],b[5007],f[5007][5007];
template<typename any>inline any abs(any x){return 0<x?-x:x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m=0;
	memset(f,0x3f,sizeof f);
	cin>>n;f[0][0]=0;
	for(i=1;i<=n;i++)cin>>a[i],a[i]?b[++m]=i:0,f[0][i]=0;
	for(i=1;i<=m;i++)for(j=1;j<=n;j++)
		if(a[j])f[i][j]=f[i][j-1];
		else f[i][j]=std::min(f[i][j-1],f[i-1][j-1]+abs(b[i]-j));
	cout<<f[m][n];
	return 0;
}