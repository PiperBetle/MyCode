#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x<y?y:x;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return 0<x?x:-x;}
int a[1007],sum[1007],f[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0x3f3f3f3f3f3f3f3f;
	
	memset(f,0x3f,sizeof f);
	for(cin>>n,i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i],f[i][i]=0;
	for(m=n<<1,i=1;i<=m;i++)sum[i]+=sum[i-1]+a[i];
	for(i=2;i<=m;i++)for(j=i-1;j;j--)for(k=j;k<i;k++)
		f[j][i]=min(f[j][i],f[j][k]+f[k+1][i]+sum[i]-sum[j-1]);
	for(i=1;i<n;i++)ans=min(ans,f[i][i+n-1]);
	cout<<ans;
	
	return 0;
}