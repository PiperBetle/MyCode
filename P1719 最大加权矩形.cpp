#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int a[1007][1007],b[1007],f[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0;

	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)cin>>a[i][j];
	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof b);
		memset(f,0,sizeof f);
		for(j=i;j<=n;j++)for(k=1;k<=n;k++)
			b[k]+=a[j][k],ans=max(ans,f[k]=max(f[k-1]+b[k],b[k]));
	}
	cout<<ans;

	return 0;
}