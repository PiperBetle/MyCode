#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 317847191
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[1000007],del[1000007],ans[1000007];
char c[1000007];
inline int qp(int a,int p,int k,int t=1){for(;p;p>>=1,a=a*a%k)if(p&1)t=t*a%k;return t;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int maxn=-1e15,minn=1e15,s=1;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	for(i=1;i<=m;i++){cin>>c[i];if(c[i]=='D'){cin>>del[i];*std::lower_bound(a+1,a+1+n,del[i])=1e15;}}
	for(i=1;i<=n;i++)if(a[i]!=1e15)maxn=max(maxn,a[i]),minn=min(minn,a[i]),s=(s*a[i])%MOD;
	for(i=m;i>=1;i--)
		if(c[i]=='D')maxn=max(maxn,del[i]),minn=min(minn,del[i]),s=(s*del[i])%MOD;
		else if(c[i]=='B')ans[i]=maxn;else if(c[i]=='S')ans[i]=minn;
		else if(c[i]=='M')ans[i]=qp(maxn,minn,MOD);else ans[i]=s;
	for(i=1;i<=m;i++)if(c[i]!='D')cout<<ans[i]<<'\n';

	return 0;
}
