#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define int long long
using namespace std;
int f[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,x;
    int a,b,c;
	
	cin>>n>>m>>x;
    for(i=1;i<=n;i++)
	{
        cin>>a>>b>>c;
        for(j=m;j>=b;j--)
            for(k=x;k>=c;k--)
                f[j][k]=max(f[j][k],f[j-b][k-c]+a);
    }
    cout<<f[m][x];
	
    return 0;
}
