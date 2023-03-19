#include<iostream>
using namespace std;
int main()
{
	int i,j,n,m,k,s=0,sum=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		s+=(1+i)*i/2;
	}
	cout<<s;
	
	return 0;
} 
