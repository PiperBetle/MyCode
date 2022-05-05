#include<iostream>
#include<cstdio>
using std::cin;using std::cout;
int f[1000007],next[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x,int y){int fx=find(x),fy=find(y);if(fx!=fy)f[fy]=fx;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,t,x,y;
	cin>>n>>m;
	for(i=1;i<=n;i++)next[i]=i+1,f[i]=i;
	while(m--)
	{
		cin>>t>>x>>y;
		if(t==1)merge(x,y);
		else if(t==2)for(i=x+1;i<=y;x=next[i],next[i]=next[y],i=x)merge(i-1,i);
		else cout<<(find(x)==find(y)?"YES\n":"NO\n");
	}
	return 0;
}