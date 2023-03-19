#include<iostream>
using namespace std;
int main()
{
	int a,b,i,j,n;
	char c,t;
	
	cin>>a>>b>>c>>n;
	if(n==1)
	{
		for(i=1;i<=a;i++)
		{
			for(j=1;j<=b;j++)
				cout<<c;
			cout<<endl;
		}		
	}
	else
	{
		for(i=1;i<=a;i++)
		{
			for(j=1;j<=b;j++)
			{
				t=' ';
				if(i==1)t=c;
				if(j==1)t=c;
				if(i==a)t=c;
				if(j==b)t=c;
				cout<<t;
			}	
			cout<<endl;
		}
	}
	
	return 0;
}
