#include<iostream>
#include<cstring>
#include<unordered_map>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int a[1007],f[1007],g[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;

	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		cin>>n;int ans1=0,ans2=0;
		for(i=1;i<=n;i++)cin>>a[i],f[i]=g[i]=1;
		for(i=1;i<=n;i++)for(j=1;j<i;j++)
		{
			if(a[i]<a[j])continue;
			if(f[j]+1>f[i])f[i]=f[j]+1,g[i]=g[j];
			else if(f[j]+1==f[i])g[i]+=g[j];
		}
		for(i=1;i<=n;i++)if(f[i]>ans1)ans1=f[i],ans2=g[i];
		cout<<ans1<<' '<<ans2<<'\n';
	}

	return 0;
}