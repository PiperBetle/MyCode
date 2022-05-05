#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x<y?y:x;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return 0<x?x:-x;}
int f[67][300007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int ans=0;
	
	for(cin>>n,i=1;i<=n;i++)cin>>t,f[t][i]=i+1;
	for(i=2;i<=58;i++)for(j=1;j<=n;j++)
	{
		if(!f[i][j])f[i][j]=f[i-1][f[i-1][j]];
		if(f[i][j])ans=i;
	}
	cout<<ans;
	
	return 0;
}