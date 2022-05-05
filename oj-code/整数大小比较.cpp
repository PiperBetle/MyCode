#include<iostream>
using namespace std;
int main()
{
	long long i,j,k,a1,a2;
	
	cin>>a1>>a2;
	if(a1>a2)cout<<">";
	else if(a1=a2)cout<<"=";
	else if(a1<a2)cout<<"<";
	
	return 0;
}
