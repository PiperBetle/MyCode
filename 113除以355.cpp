#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long a,b,i,n;
	int m=10;
	
	while(true)
	{
		cout<<"������:";
		cin>>a;
		cout<<"����:";
		cin>>b;
		cout<<"λ��:";
		cin>>n;
		cout<<"�����:";
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
