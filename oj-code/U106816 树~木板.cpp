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
	long long a,b;
	
	cin>>a>>b;
	a=a*4;
	b=b*4;
	a=a+b/64;
	b=b%64;
	cout<<a<<" "<<b;
	
	return 0;
}
