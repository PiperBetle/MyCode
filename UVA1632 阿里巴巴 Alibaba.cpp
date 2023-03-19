#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
struct treasure{int a,t;}a[10007];
int f[10007][10007][2];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;

	while(cin>>n)
	{
		for(i=2;i<=n;i++)for(j=i-1;j;j--)f[i][j][0]=f[i][j][1]=0;
		for(i=1;i<=n;i++)f[i][i][0]=f[i][i][1]=0;
		for(i=1;i<=n;i++)cin>>a[i].a>>a[i].t;
		for(i=2;i<=n;i++)for(j=i-1;j;j--)
		{
			f[j][i][0]=min(f[j+1][i][0]+a[j+1].a-a[j].a,f[j+1][i][1]+a[i].a-a[j].a);
			if(f[j][i][0]>=a[j].t)f[j][i][0]=0x3f3f3f3f;
			f[j][i][1]=min(f[j][i-1][1]+a[i].a-a[i-1].a,f[j][i-1][0]+a[i].a-a[j].a);
			if(f[j][i][1]>=a[i].t)f[j][i][1]=0x3f3f3f3f;
		}
		int ans=min(f[1][n][0],f[1][n][1]);
		if(ans==0x3f3f3f3f)cout<<"No solution\n";
		else cout<<ans<<'\n';
	}

	return 0;
}