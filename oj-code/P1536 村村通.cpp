#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int f[1007];
int find(int x){return x==f[x]? x:f[x]=find(f[x]);}
int un(int x,int y){f[find(x)]=find(y);}
int main()
{
	int i,j,k;
	int n,m,ans=-1,x,y;
	
	while(cin>>n>>m)
	{
		for(i=1;i<=n;i++)f[i]=i;
		ans=-1;
		while(m--)
		{
			cin>>x>>y;
			un(x,y);
		}
		for(i=1;i<=n;i++)if(find(i)==i)ans++;
		cout<<ans<<'\n';
	}
	
	return 0;
}
