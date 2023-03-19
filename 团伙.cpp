#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int f[10001],a[10001];
int n,m,flag,x,y,ans=0;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int un(int x,int y){f[find(x)]=find(y);}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)f[i]=i;
	while(m--)
	{
		scanf("%d%d%d",&flag,&x,&y);
		if(flag==0)un(x,y);
		else
		{
			if(!a[x])a[x]=y;
			else un(a[x],y);
			if(!a[y])a[y]=x;
			else un(a[y],x);
		}
	}
	for(i=1;i<=n;i++)if(f[i]==i)ans++;
	printf("%d",ans);
	
	return 0;
}
