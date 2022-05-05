#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
void move(int n,char a,char b,char c)
{
	if(n==1)
	{
		printf("%c->1->%c\n",a,b);
		return;
	}
	move(n-1,a,c,b);
	printf("%c->%d->%c\n",a,n,b);
	move(n-1,c,b,a);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	char a,b,c; 
	
	cin>>n;
	cin>>a>>b>>c;
	move(n,a,b,c);
	
    return 0;
}
