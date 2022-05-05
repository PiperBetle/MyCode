#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define t10(x) ((x<<1)+(x<<3))
#define d10(x) ((x>>1)+(x>>3)) 
using std::cin;using std::cout;
int a[10000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	srand(time(NULL));
	for(i=1;i<=10000000;i++)a[i]=rand();
	
	int x=time(int);
	for(i=1;i<=10000000;i++)a[i]%10;
	cout<<time(int)-x<<'\n';
	
	int x=time(int);
	for(i=1;i<=10000000;i++)a[i]-=;
	cout<<time(int)-x<<'\n';
	
	return 0;
}

