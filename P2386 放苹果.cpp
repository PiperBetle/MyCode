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
using namespace std;
int qw(int n,int m)
{
	if((n==0)||(m==1))return 1;
	if(n<m)return qw(n,n);
	return qw(n-m,m)+qw(n,m-1);
}
int main()
{
	int n,m,t;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",qw(n,m));
	}

	return 0;
}
