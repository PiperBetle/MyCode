#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
int d[1000007],f[1000007];
inline int find(int x)
{
	if(f[x]==x)return x;
	int fx=find(f[x]);
	d[x]+=d[f[x]];
	return f[x]=fx;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int x,y,z;
	
	cin>>T;while(T--)
	{
		cin>>n>>m;bool flag=0;
		for(i=0;i<=n;i++)f[i]=i,d[i]=0;
		for(i=1;i<=m;i++)
		{
			cin>>x>>y>>z;x--;
			if(flag)continue;
			int fx=find(x),fy=find(y);
			if(fx!=fy)f[fy]=fx,d[fy]=d[x]+z-d[y];
			else if(d[x]+z!=d[y])flag=1;
		}
		if(flag)cout<<"false\n";else cout<<"true\n";
	}
	
	return 0;
}
