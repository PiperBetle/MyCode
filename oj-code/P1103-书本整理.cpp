#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int f[1007][1007];//到i为止选j本书最小花费
struct book
{
	int high,wide;
};
book a[1007];
bool cmp(book x,book y)
{
	return x.high<y.high;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;

	memset(f,0x3f,sizeof f);
	scanf("%lld%lld",&n,&k);
	m=n-k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].high,&a[i].wide);
		f[i][1]=0;
	}
	sort(a+1,a+1+n,cmp);
	for(i=2;i<=n;i++)
		for(j=1;j<=i-1;j++)
			for(k=2;k<=min(i,m);k++)
				f[i][k]=min(f[i][k],f[j][k-1]+abs(a[i].wide-a[j].wide));
	int ans=f[m][m];
	for(i=m+1;i<=n;i++)
		ans=min(ans,f[i][m]);
	printf("%lld\n",ans);
	
	return 0;
}