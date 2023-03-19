#include<iostream>
using namespace std;
int main()
{
	long long x,y,n,z;
	
	cin>>n>>x>>y;
	z=y/x+1;
	if(y/x==0)z--;
	cout<<n-z;
	
	return 0;
}
