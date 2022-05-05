#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 1000000007
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[10000007],g[10000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>n;
	g[1]=1;
	for(i=2;i<=n;i++)
	{
		f[i]=3*g[i-1]%MOD;
		g[i]=(f[i-1]+2*g[i-1])%MOD;
	}
	cout<<f[n];
	
	return 0;
}
