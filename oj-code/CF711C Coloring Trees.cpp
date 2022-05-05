#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int a[107],f[107][107][107],s[107][107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,l;
	int ans=0x3f3f3f3f3f3f3f3f;

	memset(f,0x3f,sizeof f);
	cin>>n>>m>>l;
	if(n==1&&m==1&&l==1)
	{
		cin>>a[1]>>s[1][1];
		if(a[1]==0)return cout<<s[1][1]<<'\n',0;
		else return cout<<0,0;
	}
	for(k=1;k<=m;k++)f[0][0][k]=0;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)for(k=1;k<=m;k++)cin>>s[i][k];
	for(i=1;i<=n;i++)for(j=1;j<=l;j++)
		if(a[i])
		{
			for(int k1=1;k1<=m;k1++)
				if(a[i]!=k1)f[i][j][a[i]]=min(f[i][j][a[i]],f[i-1][j-1][k1]);
				else f[i][j][a[i]]=min(f[i][j][a[i]],f[i-1][j][a[i]]);
		}
		else
		{
			for(int k1=1;k1<=m;k1++)for(int k2=1;k2<=m;k2++)
				if(k2!=k1)f[i][j][k2]=min(f[i][j][k2],f[i-1][j-1][k1]+s[i][k2]);
				else f[i][j][k2]=min(f[i][j][k2],f[i-1][j][k1]+s[i][k2]);
		}
	for(k=1;k<=m;k++)ans=min(ans,f[n][l][k]);
	cout<<(ans==0x3f3f3f3f3f3f3f3f?-1:ans);
	
	return 0;
}