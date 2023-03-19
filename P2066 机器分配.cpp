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
int a[107][107],f[107],ans[107][107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;

	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
	for(i=n;i>=1;i--)for(j=m;j>=0;j--)for(k=1;k<=j;k++)
		if(f[j-k]+a[i][k]>f[j])
		{
			f[j]=f[j-k]+a[i][k];
			ans[i][j]=k;
		}
	cout<<f[m]<<'\n';
	for(i=1,j=m;i<=n;i++)cout<<i<<' '<<ans[i][j]<<'\n',j-=ans[i][j];

	return 0;
}