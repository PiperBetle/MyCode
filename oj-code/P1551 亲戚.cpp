#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[1000001];
inline int hp(){int t;scanf("%d",&t);return t;}
int find(int x){return x==f[x]? x:f[x]=find(f[x]);}
int un(int x,int y){f[find(x)]=find(y);}
int main()
{
	int n,m,p;
	
	scanf("%d%d%d",&n,&m,&p);
	while(n--)f[n]=n;
	while(m--)un(hp(),hp());
	while(p--)puts(find(hp())==find(hp())?"Yes":"No");
	
	return 0;
}
