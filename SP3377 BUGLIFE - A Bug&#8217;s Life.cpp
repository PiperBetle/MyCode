#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[1000007],d[1000007];
inline int find(int x)
{
	if(f[x]==x)return x;
	int fx=find(f[x]);
	d[x]^=d[f[x]];
	return f[x]=fx;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x,y,flag;

	cin>>T;
	for(k=1;k<=T;k++)
	{
		memset(d,0,sizeof d);flag=0;
		for(i=0;i<1000007;i++)f[i]=i;
		cout<<"Scenario #"<<k<<":\n";
		cin>>n>>m;
		while(m--)
		{
			cin>>x>>y;
			if(flag)continue;
			int fx=find(x),fy=find(y);
			if(fx!=fy){f[fx]=fy;d[fx]=d[x]^d[y]^1;}
			else if(!(d[x]^d[y]))flag=1;
		}
		if(flag)cout<<"Suspicious bugs found!\n";
		else cout<<"No suspicious bugs found!\n";
	}

	return 0;
}