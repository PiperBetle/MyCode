#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[2049][4097];
void pr(int n,int x,int y)
{
	if(n==1)
	{
		a[x][y]=a[x-1][y+1]='/';
		a[x][y+1]=a[x][y+2]='_';
		a[x][y+3]=a[x-1][y+2]='\\';
		return;
	}
	n--;
	pr(n,x,y);
	pr(n,x,y+(1<<(n+1)));
	pr(n,x-(1<<n),y+(1<<n));
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	for(i=0;i<2049;i++)
		for(j=0;j<2049;j++)
			a[i][j]=' ';
	cin>>n;
	pr(n,(1<<n),1);
	for(i=1;i<=(1<<n);i++)
		for(j=1;j<=(1<<(n+1));j++)
			cout<<a[i][j]<<(j==(1<<(n+1))?"\n":"");
	
    return 0;
}
