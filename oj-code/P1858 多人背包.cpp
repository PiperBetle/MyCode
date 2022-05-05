#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int c[207],w[207];
std::vector<int>f[5007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int ans=0;
	
	cin>>t>>m>>n;
	for(j=0;j<=m;j++)for(k=0;k<t;k++)f[j].emplace_back(-0x3f3f3f3f);
	for(f[0][0]=0,i=1;i<=n;i++)cin>>c[i]>>w[i];
	for(i=1;i<=n;i++)for(j=m;j>=c[i];j--)
	{
		for(k=0;k<t;k++)f[j].emplace_back(f[j-c[i]][k]+w[i]);
		std::sort(f[j].begin(),f[j].end(),std::greater<int>());
		f[j].erase(f[j].begin()+t,f[j].end());
	}
//	for(k=0;k<t;k++)cout<<f[m][k]<<'\n';
	for(k=0;k<t;k++)ans+=(f[m][k]<0?0:f[m][k]);
	cout<<ans;
	
	return 0;
}