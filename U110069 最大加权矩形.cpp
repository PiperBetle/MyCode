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
int llog(int x)
{
	double n=log(x)/log(2);
	if(fabs(n-(int)n)<1e-5)return n;
	return n+1;
}
int main()
{
	long long x,y,z,t;
	
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>z;
		cout<<x*y*z-1<<endl;
		cout<<llog(x)+llog(y)+llog(z)<<endl;
	}

	return 0;
}
