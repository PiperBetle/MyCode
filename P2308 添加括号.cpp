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
int f[1007][1007],ans[1007][1007],a[1007],sum[1007],s[1007];
void write(int l,int r)
{
	if(l==r){cout<<a[l];return;}
	putchar('(');
	write(l,ans[l][r]);
	putchar('+');
	write(ans[l][r]+1,r);
	putchar(')');
	s[++s[0]]=sum[r]-sum[l-1];
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;

	memset(f,0x3f,sizeof f);
	for(cin>>n,i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i],f[i][i]=0;
	for(i=2;i<=n;i++)for(j=i-1;j;j--)for(k=j;k<i;k++)
		if(f[j][i]>=f[j][k]+f[k+1][i]+sum[i]-sum[j-1])
			f[j][i]=f[j][k]+f[k+1][i]+sum[i]-sum[j-1],ans[j][i]=k;
	write(1,n);
	cout<<'\n'<<f[1][n]<<'\n';
	for(i=1;i<=s[0];i++)cout<<s[i]<<' ';

	return 0;
}