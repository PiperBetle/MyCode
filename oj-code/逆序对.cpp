#include<iostream>
using namespace std;
int main()
{
	int i,j;
	int a[10001];
	int n,sum=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++)
			if(i<j&&a[i]>a[j])sum++;
	cout<<sum;
	
	return 0;
} 
