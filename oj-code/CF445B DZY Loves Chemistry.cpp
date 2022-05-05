#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int f[10007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,x,y,ans=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		int fx=find(x),fy=find(y);
		if(fx!=fy)f[fx]=fy,ans<<=1;
	}
	cout<<ans;
	return 0;
}
