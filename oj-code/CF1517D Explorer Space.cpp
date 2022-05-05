#include<iostream>
using std::cin;using std::cout;
int lr[507][507],ud[507][507],f[2][507][507];
template<typename any>inline any min(any a,any b){return a<b?a:b;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m,k;bool now=true;
	cin>>n>>m>>k;
	if(k&1){for(i=1;i<=n;i++,cout<<'\n')for(j=1;j<=m;j++)cout<<"-1 ";return 0;}
	k>>=1;
	for(i=1;i<=n;i++)for(j=1;j<m;j++)cin>>lr[i][j];
	for(i=1;i<n;i++)for(j=1;j<=m;j++)cin>>ud[i][j];
	while(k--)for(now=!now,i=1;i<=n;i++)for(j=1;j<=m;j++)
	{
		f[now][i][j]=0x3f3f3f3f;
		if(i>1)f[now][i][j]=min(f[now][i][j],f[!now][i-1][j]+ud[i-1][j]);
		if(i<n)f[now][i][j]=min(f[now][i][j],f[!now][i+1][j]+ud[i][j]);
		if(j>1)f[now][i][j]=min(f[now][i][j],f[!now][i][j-1]+lr[i][j-1]);
		if(j<m)f[now][i][j]=min(f[now][i][j],f[!now][i][j+1]+lr[i][j]);
	}
	for(i=1;i<=n;i++,cout<<'\n')for(j=1;j<=m;j++)cout<<(f[now][i][j]<<1)<<' ';
	return 0;
}