#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int sum[2000007],f[2000007];
inline int find(int x)
{
	if(f[x]==x)return x;
	int fx=find(f[x]);
	sum[x]+=sum[f[x]];
	return f[x]=fx;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x,y,data;
	
	while(cin>>n>>m)
	{
		memset(sum,0,sizeof sum);
		for(i=0;i<=n;i++)f[i]=i;
		int ans=0;
		while(m--)
		{
			cin>>x>>y>>data;
			int fx=find(x-1),fy=find(y);
			if(fx!=fy){f[fy]=fx;sum[fy]+=sum[x-1]-sum[y]+data;}
			else ans+=(sum[y]-sum[x-1]!=data);
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
