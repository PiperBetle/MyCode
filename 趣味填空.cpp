#include<iostream>
using namespace std;
int main()
{
	long long a,b,c,d,e;
	
	scanf("%lld=%lld",&a,&b);
	e=10;
	while(e<a)
	{
		c=a/e;
		d=a%e;
		if(c*d==b)
		{
			printf("%lld*%lld=%lld\n",c,d,b);
			break;
		}
		e*=10;
	}
	if(e>=a)cout<<"Impossible";
	
	return 0;
} 
