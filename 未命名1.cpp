#include<iostream>
#include<iomanip>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	int n,m;
	int i,j,k;
	int t,tt,ttt;
	int a[101];
	
	cin>>n>>m;
	while((n!=0)||(m!=0))
	{
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n-1;i++)
			if(m>=a[i]||m<=a[i+1])
			{
				ttt=i+1;
				break;
			}
		for(i=ttt-1;i<=n;i++)
		{
			t=a[i+1];
			a[i+1]=m;
			m=t;
		}
		for(i=1;i<=n+1;i++)cout<<a[i]<<' ';
		cout<<endl;
	}
	
	return 0;
} 
