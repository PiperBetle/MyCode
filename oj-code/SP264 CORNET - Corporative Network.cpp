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
int f[1000007],d[1000007];
int find(int x)
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
	int i,j,k;
	int n,m,T;
	int x,y;
	char c;
	
	cin>>T;
	while(T--)
	{
		memset(d,0,sizeof d);
		for(i=0;i<1000007;i++)f[i]=i;
		cin>>n;
		while(cin>>c)
		{
			if(c=='O')break;
			if(c=='I')
			{
				cin>>x>>y;
				f[x]=y;
				d[x]=abs(x-y)%1000;
			}
			if(c=='E')
			{
				cin>>x;
				find(x);
				cout<<d[x]<<'\n';
			}
		}
	}
	
	return 0;
}
