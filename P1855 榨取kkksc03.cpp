#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int f[1007][1007];
int c_m[1007],c_t[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int ans=0;  
	
	cin>>n>>m>>t;
	for(i=1;i<=n;i++)
		cin>>c_m[i]>>c_t[i];
	for(i=1;i<=n;i++)
		for(j=m;j>=c_m[i];j--)
			for(k=t;k>=c_t[i];k--)
				f[j][k]=max(f[j][k],f[j-c_m[i]][k-c_t[i]]+1);
	cout<<f[m][t];
    
    return 0;
}
