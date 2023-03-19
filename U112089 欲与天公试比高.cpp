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
	int n;
	long double a,b;
	
	while(cin>>b)
	{
		a=0.5;
		if(b==0)break;
		for(n=3;;n++)
		{
			if(a>b)
			{
				
				n--;
				break;
			}
			a=a+1/(long double)n;
		}
		cout<<"TH"<<n-1<<endl;
	}
	
	return 0;
}
