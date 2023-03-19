#include<iostream>
using namespace std;
int main()
{
	int i,j;
	long long a[100];
	int n;
	
	a[1]=1;a[2]=2;a[3]=4;
	while(cin>>n)
	{
		if(n==0)break;
		for(i=4;i<=n;i++)a[i]=a[i-1]+a[i-2]+a[i-3];
		cout<<a[n]<<endl;
	}
	
	
	return 0;
} 
