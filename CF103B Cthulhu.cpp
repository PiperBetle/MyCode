#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int f[200007];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,x,y;
	
	cin>>n>>m;
	if(n!=m)
	{
		puts("NO");
		return 0;
	}
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		int fx=find(x),fy=find(y);
		if(fx!=fy)f[fx]=fy;
	}
	for(i=1;i<n;i++)
	{
		if(find(f[i])!=find(f[i+1]))
		{
			puts("NO");
			return 0;
		}
	}
	puts("FHTAGN!");
	
	return 0;
}
