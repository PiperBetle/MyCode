#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	long long x,y,t=0;
	
	cin>>x>>y;
	for(;;)
	{
		if(y==0)break;
		t=t*10+y%10;
		y/=10;
	}
	cout<<x+t;
	
	return 0;
}
