#include<iostream>
using namespace std;
int main()
{
	int i,j,n,a=0,b=0,c=0,at,bt,ct;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>at>>bt>>ct;
		a+=at;
		b+=bt;
		c+=ct;
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<a+b+c;
	
	return 0;
} 
