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
int gcd(int a,int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main()
{
	int n,m;
	
	scanf("%d%d",&n,&m);
	printf("%d",m-gcd(n,m));
	
    return 0;
}
