#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
char c[2007][2007];
int x[2007],y[2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
    int ans=0;
	
	cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='*')
            {
                x[i]++;
                y[j]++;
            }
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(c[i][j]=='*')
                ans+=(x[i]-1)*(y[j]-1);
    cout<<ans;
	
    return 0;
}