#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
int w[40007],c[40007],f[40007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int m,n,ans=0x3f3f3f3f;cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>c[i]>>w[i];
	memset(f,0x3f,sizeof f);f[0]=0;
	for(int i=1;i<=n;i++)for(int j=c[i];j<=m+m+c[i];j++)
		f[j]=std::min(f[j],f[j-c[i]]+w[i]);
	for(int j=m;j<40007;j++)ans=std::min(ans,f[j]);
	cout<<ans;
	return 0;
}