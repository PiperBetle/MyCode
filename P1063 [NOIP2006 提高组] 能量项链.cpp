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
int a[2007],f[2007][2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0;

	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
	for(i=2;i<n*2;i++)for(j=i-1;j>=1&&i-j<n;j--)for(k=j;k<i;k++)
		ans=max(ans,f[j][i]=max(f[j][i],f[j][k]+f[k+1][i]+a[j]*a[k+1]*a[i+1]));
	cout<<ans;

	return 0;
}