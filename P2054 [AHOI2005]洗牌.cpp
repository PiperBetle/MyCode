#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
		x=1,y=0;
	else
		exgcd(b,a%b,y,x),y-=a/b*x;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int a,b,l;

	//2755?
	
	return 0;
}