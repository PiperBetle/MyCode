#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#define int long long
using std::cin;using std::cout;
std::bitset<2007>f[2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0;
	char c;
	
	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)cin>>c,f[i][j]=c-48;
	for(i=1;i<=n;i++)f[i][i]=1;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(f[j][i])f[j]|=f[i];
	for(i=1;i<=n;i++)ans+=f[i].count();
	cout<<ans;
	
	return 0;
}