#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdio>
#include<algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int f[1000007],len[1000007],a[1000007][23];
bool b[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	
	for(i=2;i<=1000000;i++)
		if(!b[i])
			for(j=i;j<=1000000;j+=i)
				b[j]=1,a[j][++len[j]]=i;

	for(i=2;i<=1000000;i++)
	{
		f[i]=f[i-1]+1;
		for(j=1;j<=len[i];j++)
			f[i]=min(f[i],f[i/a[i][j]]+1);
	}
	
	while(~scanf("%d",&n))
		printf("%d\n",f[n]);
	
	return 0;
}