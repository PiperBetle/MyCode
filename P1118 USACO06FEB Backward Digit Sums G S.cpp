#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int a[17],b[17],c[17][17];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	
	for(i=1;i<17;i++)c[i][1]=c[i][i]=1;
	for(i=2;i<17;i++)for(j=2;j<i;j++)c[i][j]=c[i-1][j-1]+c[i-1][j];
	cin>>n>>m;
	for(i=1;i<=n;i++)a[i]=i;
	do
	{
		for(t=0,i=1;i<=n;i++)t+=c[n][i]*a[i];
		if(t==m){for(i=1;i<=n;i++)cout<<a[i]<<' ';return 0;}
	}while(std::next_permutation(a+1,a+1+n));
	
	return 0;
}