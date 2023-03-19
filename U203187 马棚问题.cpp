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
int f[1007][1007],s[1007][2],a[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;

	cin>>n>>m;
	memset(f,0x3f,sizeof f);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i][0]=s[i-1][0];
		s[i][1]=s[i-1][1];
		s[i][a[i]]++;
		f[i][1]=s[i][0]*s[i][1];
	}
	for(i=1;i<=n;i++)for(j=1;j<=min(m,i);j++)for(k=1;k<=i;k++)
		f[i][j]=min(f[i][j],f[k][j-1]+(s[i][0]-s[k][0])*(s[i][1]-s[k][1]));
	cout<<f[n][m];

	return 0;
}