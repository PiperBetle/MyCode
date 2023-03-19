#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	
	cin>>n;
	if((0<=n)&&(n<5))cout<<setprecision(3)<<-1.0*n+2.5;
	else if((5<=n)&&(10>n))cout<<setprecision(3)<<2-1.5*(n-3.0)*(n-3.0);
	else cout<<setprecision(3)<<n/2.0-1.5;
	
	return 0;
}
