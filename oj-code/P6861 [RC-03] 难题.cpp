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
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	long long i,j,k;
	long long n,t=1;
	
	scanf("%lld",&n);
	for(i=1;;i++)
	{
		t<<=1;
		if(n<t)
		{
			printf("%lld",(t<<1)-2);
			return 0;
		}
	}
	
	return 0;
}
