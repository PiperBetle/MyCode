#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[107][107],cnt[107];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int u,v,t;
	
	cin>>n;m=n*(n-1)>>1;
	for(i=1;i<m;i++)
	{
		cin>>u>>v;
		f[max(u,v)][min(u,v)]++;
		cnt[u]++;
	}
	for(i=1;i<=n;i++)for(j=1;j<i;j++)
	{
		if(f[i][j])continue;
		if(cnt[i]>=cnt[j])cout<<i<<' '<<j<<'\n';
		else cout<<j<<' '<<i<<'\n';
	}
	
	return 0;
}