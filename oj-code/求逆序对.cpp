#include<iostream>
using namespace std;
int main()
{
	int i,j,num=0,n,a[100001],temp;

	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++) 
		{
			if (a[i]>a[j]) 
			{
				num++;
			}
		} 
	}	
	cout<<num;
	
	return 0;
}
