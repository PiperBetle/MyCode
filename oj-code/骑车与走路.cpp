#include<iostream>
using namespace std;
int main()
{
	int n;
	double a1,a2;
	
	cin>>n;
	a1=n/1.2;
	a2=n/3.0+50;
	if(a1<a2)cout<<"Walk";
	else if(a1>a2)cout<<"Bike";
	else cout<<"All";
	
	
	return 0;
}
