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
struct block{int u,d;}a[1007];
int f[1007][12007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m=0,t;
	int del=0x3f3f3f3f3f3f3f3f,ans=0x3f3f3f3f3f3f3f3f;
	
	memset(f,0x3f,sizeof f);f[0][0]=0;
	for(cin>>n,i=1;i<=n;i++)cin>>a[i].u>>a[i].d,m+=a[i].u+a[i].d;
	for(i=1;i<=n;i++)for(j=min(a[i].u,a[i].d);j<=m;j++)
	{
		if(j>=a[i].u)f[i][j]=min(f[i][j],f[i-1][j-a[i].u]);
		if(j>=a[i].d)f[i][j]=min(f[i][j],f[i-1][j-a[i].d]+1);
	}
	for(i=0;i<=m;i++)
		if((f[n][i]!=0x3f3f3f3f3f3f3f3f)&&((abs((i<<1)-m)<del)||(abs((i<<1)-m)==del&&f[n][i]<ans)))
			ans=f[n][i],del=abs((i<<1)-m);
	cout<<ans;
	
	return 0;
}