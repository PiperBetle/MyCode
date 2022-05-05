#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	unsigned long long l,t,r;
	
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",r*r%1000000);
	}
	
	return 0;
}
