#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long a,b,i,n;
	int m=10;
	
	while(true)
	{
		cout<<"被除数:";
		cin>>a;
		cout<<"除数:";
		cin>>b;
		cout<<"位数:";
		cin>>n;
		cout<<"结果是:";
		cout<<a/b;
		a=a%b;
		cout<<".";
		for(i=1;i<=n;i++)
		{
			a=a*m;
			cout<<a/b;
			a=a%b;
		}
		cout<<endl;
	}
	
	return 0;
}
