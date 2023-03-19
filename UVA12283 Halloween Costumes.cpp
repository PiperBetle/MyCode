#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int f[107][107],a[107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int p,q,r;

	for(cin>>T,p=1;p<=T;p++)
	{
		memset(f,0x3f,sizeof f);
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>a[i],f[i][i]=1;
		for(i=2;i<=n;i++)for(j=i-1;j;j--)for(k=j;k<i;k++)
			f[j][i]=min(f[j][i],f[j][k]+f[k+1][i]-(a[j]==a[k+1]));
		cout<<"Case "<<p<<": "<<f[1][n]<<'\n';
	}

	return 0;
}