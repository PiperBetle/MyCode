#include<iostream>
using namespace std;
int main()
{
	int i,j,t,a1=0,a5=0,a10=0,n;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(t==1)a1++;
		if(t==5)a5++;
		if(t==10)a10++;
	}
	cout<<a1<<endl<<a5<<endl<<a10;
	
	return 0;
} 
