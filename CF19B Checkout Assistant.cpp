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
int w[5007],c[5007],f[5007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m=0,ans=0x3f3f3f3f3f3f3f3f;
	
	memset(f,0x3f,sizeof f);
	for(cin>>n,i=1;i<=n;i++)cin>>c[i]>>w[i],m=max(m,++c[i]);
	for(f[0]=0,m+=n,i=1;i<=n;i++)for(j=m;j>=c[i];j--)
		f[j]=min(f[j],f[j-c[i]]+w[i]);
	for(j=n;j<=m;j++)ans=min(ans,f[j]);
	cout<<ans;
	
	return 0;
}